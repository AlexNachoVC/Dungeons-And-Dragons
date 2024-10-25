#include "../../include/game_logic/Catalog.h"

Catalog::Catalog() : monsterCatalog() {
    srand(static_cast<unsigned int>(time(0)));
}

Catalog::~Catalog() {}

bool Catalog::loadMonstersFromCSV() {
    string filename = "monsters.csv";
    unsigned int loadedCount = ::loadMonstersFromCSV(filename, monsterCatalog);
    return loadedCount > 0;
}

bool Catalog::selectRandomMonster() {
    return monsterCatalog.getRandomNode();
}
