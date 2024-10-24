#pragma once

#include <iostream>
#include "Monster.h"
#include "lib/templates/BinarySearchTree.hpp"

using namespace std;

class Catalog {
private:
    BST<Monster> Catalog;

public:
    bool loadMonstersFromCSV();
    bool selectRandomMonster();
    Monster* searchMonster();
};