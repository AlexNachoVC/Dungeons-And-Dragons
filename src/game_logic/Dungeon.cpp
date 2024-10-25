#include "../../include/game_logic/Dungeon.h"

Dungeon::Dungeon() : Rooms() {}


Dungeon::~Dungeon() {

}

void Dungeon::traverseDungeon() {
    this->Rooms.printListForwards();
}

bool Dungeon::createRoom(Monster* monster) {
    if (monster == nullptr) {
        return false;
    }

    Room* newRoom = new Room(monster);
    if (newRoom == nullptr) {
        return false;
    }

    return this->Rooms.append(*newRoom);

}