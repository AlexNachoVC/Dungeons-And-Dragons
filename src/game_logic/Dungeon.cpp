#include "../../include/game_logic/Dungeon.h"

Dungeon::Dungeon() : Rooms() {}


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
    Rooms.setVertex(roomNumber, newRoom);
    return true;
}