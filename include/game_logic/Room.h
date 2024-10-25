#pragma once

#include <iostream>
#include "Monster.h"
#include "Catalog.h"
using namespace std;

class Room {
private:
    Monster roomMonster;
    int roomNumber;

public:
    Room();
    Room(Monster& monster, int number);
    ~Room();

    friend ostream& operator<<(ostream& os, const Room& Room);
};