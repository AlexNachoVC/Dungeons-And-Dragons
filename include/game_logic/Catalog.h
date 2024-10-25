#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Monster.h"
#include "../../lib/templates/BinarySearchTree.hpp"
#include "../../lib/helpers/CSVLoader.h"

using namespace std;

class Catalog {
private:
    BST<Monster> monsterCatalog;

public:
    Catalog();
    ~Catalog();
    
    bool loadMonstersFromCSV(const string& fileName);
    Monster* selectRandomMonster();
};