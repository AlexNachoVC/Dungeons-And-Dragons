#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Monster.h"
#include "../../lib/templates/BinarySearchTree.hpp"
#include "../../lib/templates/HashTables.hpp"

using namespace std;

class Catalog {
private:
    HashTable<Monster> monsterCatalog;

public:
    Catalog();
    ~Catalog();
    
    bool loadMonstersFromCSV(const string& fileName);
    static unsigned int hashMonster(Monster &monster, unsigned int tableSize) {
        string value;
        unsigned int hashValue = 0, size = 0;

        value = monster.getName();
        size = value.size();

        for (unsigned int i = 0; i < size; i++) {
            hashValue += value[i];
        }
        
        value = monster.getType();
        size = value.size();

        for (unsigned int i = 0; i < size; i++) {
            hashValue += value[i];
        }

        hashValue *= monster.getArmorClass();
        hashValue *= monster.getHitPoints();

        return hashValue % tableSize;
    }

    Monster* selectRandomMonster();
};