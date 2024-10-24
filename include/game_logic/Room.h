#pragma once

#include <iostream>
#include "Monster.h"
#include "Catalog.h"
using namespace std;

class Room {
private:
    Monster roomMonster;

public:
    Room();
    Room(Monster roomMonster);
    ~Room();
    bool assignRandomMonster(Catalog);
};