#include "../../include/game_logic/Catalog.h"

Catalog::Catalog() : monsterCatalog() {
    srand(static_cast<unsigned int>(time(0)));
}

Catalog::~Catalog() {}

bool Catalog::loadMonstersFromCSV(const string& fileName) {
    unsigned int loadedCount = ::loadMonstersFromCSV(fileName, monsterCatalog);
    return loadedCount > 0;
}

Monster* Catalog::selectRandomMonster() {
    return monsterCatalog.getRandomNode();
}
