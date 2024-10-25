#include "../../include/game_logic/Dungeon.h"

Dungeon::Dungeon() : Rooms() {}


Dungeon::~Dungeon() {

}

void Dungeon::traverseDungeon() {
    this->Rooms.printListForwards();
}

void Dungeon::createRoom(Monster* monster) {
    Room* newRoom = new Room(monster);
    this->Rooms.append(*newRoom);
}