#include "../../include/game_logic/Dungeon.h"

Dungeon::Dungeon() : Rooms(), currentPosition(path.begin()) {}


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
    if (Rooms.printPath(start, end, path)) {
        currentPosition = path.begin();
        return true;
    }

    return false;
}

Room* Dungeon::currentRoomRoute() {
    if (&currentPosition) {
        return &(*currentPosition);
    }
    else {
        return nullptr;
    }
}

bool Dungeon::moveRoute() {
    if (currentRoomRoute()) {
        ++currentPosition;
        return true;
    }
    return false;
}