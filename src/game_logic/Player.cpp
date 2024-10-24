#include "../../include/game_logic/Player.h"
#include "Player.h"

Player::Player() : hitPoints(0), race(""), name(""), magicPoints(0), defeatedMonsters() {}

Player::Player(int hitPoints, string race, string name, int magicPoints, LinkedList<Monster> defeatedMonsters) {
    this->hitPoints = hitPoints;
    this->race = race;
    this->name = name;
    this->magicPoints = magicPoints;
    this->defeatedMonsters = defeatedMonsters;
}

Player::~Player() {

}

int Player::getHitPoints() {
    return hitPoints;
}

string Player::getRace() {
    return race;
}

string Player::getName() {
    return name;
}

int Player::getMagicPoints(){
    return magicPoints;
}

void Player::setHitPoints(int hitPoints) {
    this->hitPoints = hitPoints;
}

void Player::setRace(string race) {
    this->race = race;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setMagicPoints(int magicPoints) {
    this->magicPoints = magicPoints;
}

bool Player::addDefeatedMonster(Monster nMonster) {
    defeatedMonsters.insertOnOrder(nMonster);
}

void Player::displayDefeatedMonsters() {
    defeatedMonsters.printList();
}