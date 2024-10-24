#include "../../include/game_logic/Room.h"

Room::Room() : roomMonster() {}

Room::Room(Monster roomMonster) {
    this->roomMonster = roomMonster;
}

Room::~Room() {

}

ostream& operator<<(ostream& os, const Room& Room) {
    os << "Cuarto con: " << Room.roomMonster;
    return os;
}