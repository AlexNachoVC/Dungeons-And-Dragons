#include "../../include/game_logic/Dungeon.h"

Dungeon::Dungeon() : Rooms() {}


Dungeon::~Dungeon() {

}

void Dungeon::traverseDungeon() {
    this->Rooms.printListForwards();
}