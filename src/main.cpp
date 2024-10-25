#include <iostream>
#include "include/game_logic/Catalog.h"
#include "include/game_logic/Dungeon.h"
#include "include/game_logic/Monster.h"
#include "include/game_logic/Player.h"
#include "include/game_logic/Room.h"

using namespace std;

#define NUM_CUARTOS 20

int main() {
    Catalog myCatalog;
    Dungeon myDungeon;

    if (!myCatalog.loadMonstersFromCSV("monsters.csv")) {
        cout << "No se pudo crear el catalogo" << endl;
        return 0;
    }

    cout << "Creando Dungeon..." << endl;
    for (int c = 0; c < NUM_CUARTOS; c++) {
        Monster *pMonster = nullptr, copiaMonstruo;

        pMonster = myCatalog.selectRandomMonster();
        if (!pMonster) {
            cout << "No se pudo obtener un monstruo del catalogo" << endl;
            return 0;
        }

        copiaMonstruo = *pMonster;
        if(!myDungeon.)
    }
}