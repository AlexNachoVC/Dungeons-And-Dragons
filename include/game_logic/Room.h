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
    ~Room();

    friend ostream& operator<<(ostream& os, const Room& Room);
};