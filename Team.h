#ifndef TEAM_H
#define TEAM_H
#include "Player.h"
#include <string>
using namespace std;
class Team
{
public:
    Team();
    ~Team();
    Team(const string name, const string color, const int year);
    void addPlayer(const string pName,const string pPosition);
    void removePlayer( const string pName);
    string getColor() const;
    void setColor(const string color);
    string getName() const;
    void setName(const string name);
    int getYear() const;
    void setYear(const int year);
    void displayAllPlayers() const;
    bool getPlayerInfo(const string pName) const;
    void getPrintPlayerInfo(const string pName) const;
    string ifStringsEqual(const string string_1, const bool func) const;

private:

    struct PlayerNode
    {
        Player p;
        PlayerNode* next;
    };

    PlayerNode *head;
    int playerCount;
    PlayerNode* findPlayer(const string playerName) const;
    string name;
    string color;
    int year;
};
#endif
