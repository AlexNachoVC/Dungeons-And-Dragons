#include "../../include/game_logic/Catalog.h"

Catalog::Catalog() : monsterCatalog() {
    srand(static_cast<unsigned int>(time(0)));
}

Catalog::~Catalog() {}

bool Catalog::loadMonstersFromCSV(const string& fileName) {
    ifstream        file(fileName);
    string          line;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return false;
    }

    if (!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return false;
    }

    cout << "Cargando archivo: " << fileName << endl;

    while (getline(file, line)) {
        Monster         nMonster;
        stringstream    ss(line);
        string          cell;
        int             campo = 0, errores = 0;

        while (getline(ss, cell, ',')) {
            if (!cell.length())
                errores++;
            switch (campo) {
            case 0:
                nMonster.setName(cell);
                break;
            case 1:
                nMonster.setChallengeRating(stof(cell));
                break;
            case 2:
                nMonster.setType(cell);
                break;
            case 3:
                nMonster.setSize(cell);
                break;
            case 4:
                nMonster.setArmorClass(stoi(cell));
                break;
            case 5:
                nMonster.setHitPoints(stoi(cell));
                break;
            case 6:
                nMonster.setAlignment(cell);
                break;
            default:
                errores++;
                break;
            }

            campo++;
        }
        if (errores) {
            cerr << "Error en la linea: " << endl << line << endl;
            file.close();
            return false;
        }
        monsterCatalog.insert(nMonster);
    }
    file.close();
    return true;
}

Monster* Catalog::selectRandomMonster() {
    return monsterCatalog.getRandomNode();
}
