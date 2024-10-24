#pragma once

#include <string>
#include "include/game_logic/Monster.h"


#define MONSTER_ATTRIB_SIZE 7

unsigned int loadMonstersFromCSV(const std::string& fileName, Monster **&monsterArray, unsigned int &arraySize,  unsigned int currentPos); 

int countDataLinesInCSV(const std::string& fileName);
