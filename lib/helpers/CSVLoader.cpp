#include "CSVLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

unsigned int loadMonstersFromCSV(const std::string& fileName, Monster **&monsterArray, unsigned int &arraySize, unsigned int currentPos) {
    std::ifstream file(fileName);
    std::string line;
    unsigned int size = currentPos;

    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << fileName << std::endl;
        return 0;
    }

    // skip header
    if(!std::getline(file, line)) {
        std::cerr << "El archivo no tiene header" << std::endl;
        file.close();
        return 0;
    }

    std::cout << "Cargando archivo: " << fileName << std::endl;

    while (std::getline(file, line)) {
        Monster        nMonster;
        std::stringstream    ss(line);
        std::string          cell;
        int             campo = 0, errores = 0;


        if(fileName == "monsters.csv") {
            Monster nMonster;

            while (std::getline(ss, cell, ',')) {
                if(!cell.length())
                    errores ++;

                switch(campo) {
                    case 0:
                        nMonster.setName(cell);
                        break;
                    case 1:
                        nMonster.setChallengeRating(std::stoi(cell));
                        break;
                    case 2:
                        nMonster.setType(cell);
                        break;
                    case 3:
                        nMonster.setsSize(cell);
                        break;
                    case 4:
                        nMonster.setArmorClass(std::stoi(cell));
                        break;
                    case 5:
                        nMonster.setHitPoints(std::stoi(cell));
                        break;
                    case 6:
                        nMonster.setAlignment(cell);
                        break;

                    default:
                        errores ++;
                        break;
                }
                campo ++;
            }

            if(errores || campo != MONSTER_ATTRIB_SIZE) {
                std::cerr << "Error en la linea: " << std::endl << line << std::endl;
                file.close();
                return 0;
            }

            if(size < arraySize) {
                monsterArray[size] = new Monster(nMonster);
                size ++;
                currentPos++;
            }
            else {
                std::cerr << "Error, el arreglo es muy pequeño" << std::endl;
                file.close();
                return 0;
            }
        }
        else {
            std::cerr << "Tipo de archivo desconocido: " << std::endl;
            file.close();
            return 0;
        }
    }

    file.close();
    return currentPos;
}

int countDataLinesInCSV(const string& fileName) {
    ifstream    file(fileName);
    int         lineCount = 0;
    string      line;

    // Contar la cantidad de líneas en el archivo csv
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return -1;
    }

    // skip header
    if(!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return -1;
    }

    // Contar lineas 
    while(getline(file, line)) {
        lineCount++;    
    }

    file.close();
    return(lineCount);
}