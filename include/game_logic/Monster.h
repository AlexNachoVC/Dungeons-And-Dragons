#pragma once

#include <iostream>

using namespace std;

class Monster {
private:
    string name;
    int challengeRating;
    string type;
    string size;
    int armorClass;
    int hitPoints;
    string alignment;

public:
    Monster();
    Monster(string name, int challengeRating, string type, string size, int armorClass, int hitPoints, string alignment);
    ~Monster();

    string getName();
    int getChallengeRating();
    string getType();
    string getsSize();
    int getArmorClass();
    int getHitPoints();
    string getAlignment();

    void setName(string name);
    void setChallengeRating(int challengeRating);
    void setType(string type);
    void setsSize(string size);
    void setArmorClass(int armorClass);
    void setHitPoints(int hitPoints);
    void setAlignment(string alignment);

    void displayStats();

    friend ostream& operator<<(ostream& os, const Monster& monster) {
        os << monster.name;
        return os;
    }

    bool operator<(const Monster& other) const {
        return this->name < other.name;
    }

    bool operator>(const Monster& other) const {
        return this->name > other.name;
    }
};