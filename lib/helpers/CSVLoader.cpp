#include "CSVLoader.h"
#include "../../include/game_logic/Monster.h"
#include "../../lib/templates/BinarySearchTree.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool loadFromCSV(const std::string& fileName, BST<Monster>& monsterCatalog) {
    ifstream        file(fileName);
    string          line;
    unsigned int    size = 0;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return false;
    }

    if (!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return false;
    }

    cout << "Cargando archivo: " << fileName << endl;

    while (getline(file, line)) {
        Monster         nMonster;
        stringstream    ss(line);
        string          cell;
        int             campo = 0, errores = 0;

        while (getline(ss, cell, ',')) {
            if (!cell.length())
                errores++;
            switch (campo) {
            case 0:
                nMonster.setName(cell);
                break;
            case 1:
                nMonster.setChallengeRating(stof(cell)); // Convertir string a float
                break;
            case 2:
                nMonster.setType(cell);
                break;
            case 3:
                nMonster.setsSize(cell);
                break;
            case 4:
                nMonster.setArmorClass(stoi(cell)); // Convertir string a int
                break;
            case 5:
                nMonster.setHitPoints(stoi(cell)); // Convertir string a int
                break;
            case 6:
                nMonster.setAlignment(cell);
                break;
            default:
                errores++;
                break;
            }

            campo++;
        }
        if (errores) {
            cerr << "Error en la linea: " << endl << line << endl;
            file.close();
            return false;
        }
        monsterCatalog.insert(nMonster);
    }
    file.close();
    return true;
}

int countDataLinesInCSV(const string& fileName) {
    ifstream    file(fileName);
    int         lineCount = 0;
    string      line;

    // Contar la cantidad de líneas en el archivo csv
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return -1;
    }

    // skip header
    if(!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return -1;
    }

    // Contar lineas 
    while(getline(file, line)) {
        lineCount++;    
    }

    file.close();
    return(lineCount);
}