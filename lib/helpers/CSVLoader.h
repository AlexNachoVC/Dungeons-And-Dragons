#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "include/game_logic/Monster.h"
#include "lib/templates/BinarySearchTree.hpp"


#define MONSTER_ATTRIB_SIZE 7

unsigned int loadMonstersFromCSV(const std::string& fileName, BST<Monster>& monsterCatalog);

int countDataLinesInCSV(const std::string& fileName);
