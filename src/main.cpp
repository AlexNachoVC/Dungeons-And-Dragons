#include <iostream>
#include "game_logic/Catalog.h"
#include "game_logic/Dungeon.h"
#include "game_logic/Monster.h"
#include "game_logic/Player.h"
#include "game_logic/Room.h"

using namespace std;

int main() {
    Catalog myCatalog;
    Dungeon myDungeon;

    if (!myCatalog.loadMonstersFromCSV("assets/monsters.csv")) {
        cout << "No se pudo crear el catalogo" << endl;
        return 0;
    }

    cout << "Creando Dungeon..." << endl;
    if (!myDungeon.createDungeon("assets/dungeon.txt")) {
        cout << "No se pudo crear el Dungeon" << endl;
        return 0;
    }

    for (unsigned int c = 0; c < myDungeon.getSize(); c++) {
        Monster *pMonster = nullptr, copiaMonstruo;

        pMonster = myCatalog.selectRandomMonster();
        if (!pMonster) {
            cout << "No se pudo obtener un monstruo del catalogo" << endl;
            return 0;
        }

        copiaMonstruo = *pMonster;
        if(!myDungeon.createRoom(c, copiaMonstruo)) {
            cout << "No se pudo insertar cuarto con monstruo al calabozo" << endl;
            return 0;
        }
    }

    myDungeon.traverseDungeon();

    return 0;
}