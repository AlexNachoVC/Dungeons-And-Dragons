#pragma once

#include <iostream>
#include "Room.h"
#include "../../lib/templates/Graph.hpp"

using namespace std;

class Dungeon {
private:
    Graph<Room> Rooms;

public:
    Dungeon();
    ~Dungeon();
    unsigned int getSize();
    void traverseDungeon();
    bool createRoom(unsigned int roomNumber, Monster monster);
    bool createDungeon(string filename);
    bool traceRoute(unsigned int start, unsigned int end);
    Room* currentRoomRoute();
    bool moveRoute();
};