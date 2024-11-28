#pragma once
#include "DoublyLinkedList.hpp"
#include "Queue.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

template <typename T>
class Vertex {
public:
    T data;
    DoublyLinkedList<unsigned int> edges;
    bool visited;
    Vertex() : data(), visited(false) {}
};

template <typename T>
class Graph {
private:
    Vertex<T>* vertexes;
    unsigned int size;
    unsigned int* previous;

    void clearVisited() {
        for (unsigned int i = 0; i < size; ++i) {
            vertexes[i].visited = false;
        }
    }

    bool isValidNumeric(const string& str) {
		for (char c : str) {
			if (!isdigit(c)) {
				return false;
			}
		}
		return true;
	}

public:
    Graph() {
        vertexes = nullptr;
        size = 0;
        previous = nullptr;
    }

    ~Graph() { deleteGraph(); }

    bool createGraph(unsigned int nSize) {
        if (nSize == 0 || vertexes || previous) {
            return false;
        }

        vertexes = new (std::nothrow) Vertex<T>[nSize];
        if (!vertexes) {
            return false;
        }

        size = nSize;
            
        previous = new(nothrow) unsigned int[nSize];
		if (!previous) {
			return false;
		}

        for (unsigned int i = 0; i < size; ++i) {
            previous[i] = UINT32_MAX;
        }

        return true;
    }

    void deleteGraph() {
        if (!size) {
            return;
        }
        if (vertexes) {
            delete[] vertexes;
            vertexes = nullptr;
        }

        if (previous) {
            delete[] previous;
            previous = nullptr;
        }
        size = 0;
    }

    bool setVertex(unsigned int vertex, T data) { 
        if (!size || vertex >= size) {
            return false;
        }
        vertexes[vertex].data = data;
        return true;
    }

    T* getVertexData(unsigned int vertex) {
        if (vertex >= size || !vertexes) {
			return nullptr;
		}

        return &vertexes[vertex].data;
    }

    unsigned int getSize() {
        return size;
    }

    bool insertEdge(unsigned int source, unsigned int destination) {
        if (!vertexes) {
            return false;
        }

        if (source >= size || destination >= size) {
            return false;
        }

        if (vertexes[source].edges.search(destination)) {
            return false;
        }

        return vertexes[source].edges.append(destination);
    }

    bool deleteEdge(unsigned int source, unsigned int destination) {
        if (!vertexes) {
            return false;
        }

        if (source >= size || destination >= size) {
            return false;
        }

        return vertexes[source].edges.deleteElement(destination);
    }

    void printGraph() {
        for (unsigned int i = 0; i < size; ++i) {
            cout << vertexes[i].data << "Conexiones con los cuartos: ";
            vertexes[i].edges.printListForwards();
            cout << endl;
        }
    }

    void DFS(unsigned int vertex) {
        vertexes[vertex].visited = true;
        cout << vertex << " ";

        DoublyLinkedList<int>::Iterator i(nullptr);
        for (auto edge : vertexes[vertex].edges) {
            if (!vertexes[*edge].visited) {
                DFS(*edge);
            }
        }
    }

    bool BFS(unsigned int startVertex) {
        Queue<unsigned int> queue;

        if (!size || startVertex >= size) {
            delete[] previous;
            return false;
        }

        clearVisited();

        //cout << "BFS(" << startVertex << "): ";

        if (!queue.enqueue(startVertex)) {
            delete[] previous;
            return false;
        }
        vertexes[startVertex].visited = true;

        while (!queue.isEmpty()) {
            unsigned int vertex = *queue.peek();

            //cout << vertex << " ";
            queue.deque();

            for (auto edge : vertexes[vertex].edges) {
                if (!vertexes[edge].visited) {
                    if (!queue.enqueue(edge)) {
                        delete[] previous;
                        return false;
                    }
                    vertexes[edge].visited = true;
                    previous[edge] = vertex;
                }
            }
        }

        cout << "\n";
        return true;
    }

    bool printPath(unsigned int startVertex, unsigned int endVertex, DoublyLinkedList<T> &path) {
        DoublyLinkedList<unsigned int> breadcrumbs;  
		if (!BFS(startVertex)) {   
			return false;
		}
        
        for (unsigned int vertex = endVertex; vertex != UINT32_MAX; vertex = previous[vertex]) {
			T* data = getVertexData(vertex);
			if (!data) {
                cout << "Error: Vertex data is null for vertex " << vertex << endl;
				return false;
			}
			if (!path.prepend(*data)) {  
				return false;
			}
			if (!breadcrumbs.prepend(vertex)) {
				return false;
			}
		}

		breadcrumbs.printListForwards();   
		return true;
    }
    
    bool loadFile(const string& filename) {
		ifstream        file(filename);
		string          line;
		unsigned int source = 0, nSize = 0;

		if (!file.is_open()) {
			cerr << "Error opening file: " << filename << endl;
			return false;
		}
		if (!getline(file, line)) {
			cout << "No header" << endl;
			file.close();
			return false;
		}
		if (line != "Grafo") {
			file.close();
			return false;
		}
		if (!getline(file, line)) {  
			cout << "No graph size" << endl;
			file.close();
			return false;
		}
		if (!isValidNumeric(line)) {
			cout << "Graph size is not numerical" << endl;
			file.close();
			return false;
		}
		nSize = stoi(line);
		if (nSize <= 0) {
			cout << "Incorrect graph size" << endl;
			file.close();
			return false;
		}
		deleteGraph();   
		if (!createGraph(nSize)) {   
			cout << "The graph could not be created" << endl;
			file.close();
			return false;
		}
		for (source = 0; source < size; source++) {
			if (!getline(file, line)) {  
				cout << "No edges" << endl;
				file.close();
				return false;
			}
			if (line.length()) {    
				stringstream ss(line);
				string cell;
				while (getline(ss, cell, ' ')) {
					int destination = 0;
					if (!isValidNumeric(cell)) {
						file.close();
						return false;
					}
					destination = stoi(cell);
					if (!insertEdge(source, destination)) {
						file.close();
						return false;
					}
				}
			}
		}
		file.close();
		return true;
	}

	bool saveFile(const string& filename) {
		ofstream file;
		if (!size) {
			return false;
		}
		file.open(filename, ios::out);
		if (!file.is_open()) {
			cerr << "Error saving file: " << filename << endl;
			return false;
		}
		file << "Grafo" << endl;    
		file << size << endl;       
		for (unsigned int vertex = 0; vertex < size; vertex++) {
			for (auto edge : vertexes[vertex].edges) {
				file << edge << " ";
			}
			file << endl;
		}
		file.close();
		return true;
	}

};