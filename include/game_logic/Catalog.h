#pragma once

#include <iostream>
#include "Monster.h"
#include "lib/templates/BinarySearchTree.hpp"

using namespace std;

class Catalog {
private:
    BST<Monster> monsterCatalog;

public:
    Catalog();
    Catalog(BST<Monster> monsterCatalog);
    ~Catalog();
    
    bool loadMonstersFromCSV();
    bool selectRandomMonster();
    Monster* searchMonster();
};