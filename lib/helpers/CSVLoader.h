#pragma once


#include <string>
#include "../../include/game_logic/Monster.h"
#include "../../lib/templates/BinarySearchTree.hpp"

#define MONSTER_ATTRIB_SIZE 7

bool loadFromCSV(const std::string& fileName, BST<Monster>& monsterCatalog);

int countDataLinesInCSV(const std::string& fileName);
