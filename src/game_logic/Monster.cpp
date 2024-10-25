#include "../../include/game_logic/Monster.h"
#include "Monster.h"

Monster::Monster() : name(""), challengeRating(0), type(""), size(""), armorClass(0), hitPoints(0), alignment("") {}

Monster::Monster(string name, int challengeRating, string type, string size, int armorClass, int hitPoints, string alignment) {
    this->name = name;
    this->challengeRating = challengeRating;
    this->type = type;
    this->size = size; 
    this->armorClass = armorClass;
    this->hitPoints = hitPoints;
    this->alignment = alignment;
}

Monster::~Monster() {

}

string Monster::getName()
{
    return name;
}

int Monster::getChallengeRating()
{
    return challengeRating;
}

string Monster::getType()
{
    return type;
}

string Monster::getsSize()
{
    return size;
}

int Monster::getArmorClass()
{
    return armorClass;
}

int Monster::getHitPoints()
{
    return hitPoints;
}

string Monster::getAlignment()
{
    return alignment;
}

void Monster::setName(string name) {
    this->name = name;
}

void Monster::setChallengeRating(int challengeRating) {
    this->challengeRating = challengeRating;
}

void Monster::setType(string type) {
    this->type = type;
}

void Monster::setsSize(string size) {
    this->size = size;
}

void Monster::setArmorClass(int armorClass) {
    this->armorClass = armorClass;
}

void Monster::setHitPoints(int hitPoints) {
    this->hitPoints = hitPoints;
}

void Monster::setAlignment(string alignment) {
    this->alignment = alignment;
}

void Monster::displayStats() {
    cout << "Name: " << this->name << endl;
    cout << "Challenge Rating: " << this->challengeRating << endl;
    cout << "Type: " << this->type << endl;
    cout << "Size: " << this->size << endl;
    cout << "Armor Class: " << this->armorClass << endl;
    cout << "Hit Points: " << this->hitPoints << endl;
    cout << "Alignment: " << this->alignment << endl;
}
