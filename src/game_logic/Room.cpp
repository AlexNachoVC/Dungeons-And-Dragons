#include "../../include/game_logic/Room.h"

Room::Room() : roomMonster(), roomNumber(0) {}

Room::Room(Monster& monster, int number) : roomMonster(monster), roomNumber(number) {}

Room::~Room() {

}

ostream& operator<<(ostream& os, const Room& Room) {
    os << "Cuarto " << Room.roomNumber << " con: " << Room.roomMonster << endl;
    return os;
}