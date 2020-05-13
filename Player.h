#ifndef __PLAYER_H
#define __PLAYER_H
#include <string>
using namespace std;
class Player
{
public:
    Player();
    Player(const string name, const string position);
    string getPlayerName() const;
    void setPlayerName(const string name);
    string getPosition() const;
    void setPosition(const string position);
private:
    string name;
    string position;
};
#endif
