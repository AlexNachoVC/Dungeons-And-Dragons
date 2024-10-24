#pragma once

#include <iostream>
#include "lib/templates/SinglyLinkedlist.hpp"
#include "Monster.h"

using namespace std;

class Player {
private:
    int hitPoints;
    string race;
    string name;
    int magicPoints;
    LinkedList<Monster> defeatedMonsters;

public:
    Player();
    Player(int hitPoints, string race, string name, int magicPoints, LinkedList<Monster> defeatedMonsters);
    ~Player();

    int getHitPoints();
    string getRace();
    string getName();
    int getMagicPoints();

    void setHitPoints(int hitPoints);
    void setRace(string race);
    void setName(string name);
    void setMagicPoints(int magicPoints);

    bool addDefeatedMonster(Monster);
    void displayDefeadedMonsters();
};