#include "../../include/game_logic/Dungeon.h"

Dungeon::Dungeon() : Rooms(), currentPosition(path.end()) {}


Dungeon::~Dungeon() {
    Rooms.deleteGraph();
}

unsigned int Dungeon::getSize() {
    return Rooms.getSize();
}

void Dungeon::traverseDungeon() {
    this->Rooms.printGraph();
}

bool Dungeon::createDungeon(string filename) {
    return Rooms.loadFile(filename);
}

bool Dungeon::createRoom(unsigned int roomNumber, Monster monster) {
    Room newRoom(monster, roomNumber);
    return Rooms.setVertex(roomNumber, newRoom);
}

bool Dungeon::traceRoute(unsigned int start, unsigned int end) {
    if (!Rooms.BFS(start)) {
        return false; 
    }

    currentPosition = path.begin();

    return Rooms.printPath(start, end, path);
}

Room* Dungeon::currentRoomRoute() {
    if (currentPosition != path.end()) {
        return &(*currentPosition);
    }
    
    return nullptr;
}

bool Dungeon::moveRoute() {
    if (currentRoomRoute()) {
        ++currentPosition;
        return true;
    }
    return false;
}