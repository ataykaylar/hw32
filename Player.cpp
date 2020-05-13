#include "Player.h"
Player::Player()
{
    name = "";
    position = "";
}

Player::Player(const string name, const string position){

    this->name = name;
    this->position = position;
}


string Player::getPlayerName() const{
    return name;

}

void Player::setPlayerName(const string name){
    this->name = name;
}

string Player::getPosition() const{
    return position;
}

void Player::setPosition(const string position){
    this->position = position;
}
