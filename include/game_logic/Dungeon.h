#pragma once

#include <iostream>
#include "Room.h"
#include "../../lib/templates/DoublyLinkedList.hpp"

using namespace std;

class Dungeon {
private:
    DoublyLinkedList<Room> Rooms;

public:
    Dungeon();
    ~Dungeon();
    void traverseDungeon();
    bool createRoom(Monster* monster);
};