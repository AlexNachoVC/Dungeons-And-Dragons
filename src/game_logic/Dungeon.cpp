#include "../../include/game_logic/Dungeon.h"

Dungeon::Dungeon() : Rooms() {}


Dungeon::~Dungeon() {
    Rooms.deleteLinkedList();
}

void Dungeon::traverseDungeon() {
    this->Rooms.printListForwards();
}

bool Dungeon::createRoom(Monster& monster, int roomNumber) {
    Room newRoom(monster, roomNumber);
    return this->Rooms.append(newRoom);
}