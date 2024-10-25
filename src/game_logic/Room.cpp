#include "../../include/game_logic/Room.h"

Room::Room(Monster* monster) : roomMonster(*monster) {}

Room::~Room() {

}

ostream& operator<<(ostream& os, const Room& Room) {
    os << "Cuarto con: " << Room.roomMonster;
    return os;
}