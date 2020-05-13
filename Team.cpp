#include "Team.h"
#include <iostream>
using namespace std;
Team::Team()
{
    color = "";
    name = "";
    year = 0;
    playerCount = 0;
    head = NULL;
}

Team::Team(const string name, const string color, const int year)
{
    this->name = name;
    this->color = color;
    this->year = year;

}


string Team::getColor() const
{
    return color;

}

void Team::setColor(const string color)
{
    this->color = color;
}

string Team::getName() const
{
    return name;
}

void Team::setName(const string name)
{
    this->name = name;

}


int Team::getYear() const
{
    return year;
}

void Team::setYear(const int year)
{
    this->year = year;

}


void Team::addPlayer( const string pName, const string pPosition)
{
     PlayerNode *newPtr = new PlayerNode;
    PlayerNode *cur = findPlayer(pName);
    (newPtr -> p).setPlayerName(pName);
    (newPtr -> p).setPosition(pPosition);

    if(cur != NULL)
    {
        cout << "Please enter a unique player!" << endl;
    }
    else if(head == NULL)
    {
        head = newPtr;
        newPtr->next = NULL;
        playerCount++;
        return;
    }
    else if(ifStringsEqual(pName,0) == "")
    {
        for(PlayerNode *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if(ptr->next == NULL)
            {
                ptr->next = newPtr;
                newPtr->next = NULL;
                playerCount++;
                return;

            }
        }
    }

}

void Team::removePlayer (const string pName)
{
    PlayerNode *deletePtr = findPlayer(pName);
    PlayerNode *prev;
    if(ifStringsEqual(pName, 1) == "" )
    {
        cout << "Please enter a existing player name!" << endl;
        return;
    }
    if(ifStringsEqual(pName, 1) != "")
    {
        string temp = ifStringsEqual(pName, 1);
        deletePtr = findPlayer(temp);
    }
    if((deletePtr->p).getPlayerName() == (head->p).getPlayerName())
    {
        prev = head;
        prev = head->next;
        head->next = NULL;
        head = prev;
        playerCount--;
    }
    else
    {
        for(PlayerNode *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if(ptr->next == deletePtr)
            {
                prev = ptr;
            }
        }
        prev->next = deletePtr->next;
        deletePtr->next = NULL;
        delete deletePtr;
        deletePtr = NULL;
       playerCount--;
    }
}
bool Team::getPlayerInfo(const string pName) const{
    for(PlayerNode *ptr = head; ptr!=NULL; ptr = ptr->next){
           if(pName == ptr->p.getPlayerName()){
                return true;
           }
    }
    return false;
}
void Team::getPrintPlayerInfo(const string pName) const{
for(PlayerNode *ptr = head; ptr!=NULL;ptr = ptr->next){
           if(pName == ptr->p.getPlayerName()){
                cout << ptr->p.getPosition() <<", "<< name<<", "<< color <<", "<<year<<endl;
                return;
           }
    }
}


void Team::displayAllPlayers() const
{
    for(PlayerNode *printPtr = head; printPtr!=NULL; printPtr = printPtr->next)
        cout << "Player: "<< (printPtr->p).getPlayerName() << " Position: "<< printPtr->p.getPosition() <<endl;
    if(head == NULL){
        cout <<"-EMPTY-"<<endl;
    }

}


Team::PlayerNode *Team::findPlayer(const string playerName) const
{
    for (PlayerNode *skip = head ; skip != NULL; skip = skip->next)
    {
        if(skip->p.getPlayerName() == playerName )
            return skip;
    }

    return NULL;
}


string Team::ifStringsEqual(const string string_1, const bool func) const{
 unsigned int counter = 0;
    for(PlayerNode *lowPtr = head; lowPtr !=NULL ; lowPtr = lowPtr->next)
    {
        if((lowPtr->p).getPlayerName().size() == string_1.size())
        {
            for(unsigned int i = 0; i < string_1.size(); i++)
            {
                if(tolower(string_1[i]) == tolower((lowPtr->p).getPlayerName()[i]))
                {
                    counter++;

                }
                if(counter == string_1.size() && func == 0)
                {
                    cout << "Please enter a unique player for " << string_1<<endl;
                    return string_1;
                }

                if(counter == string_1.size() && func == 1)
                {
                    return lowPtr->p.getPlayerName();
                }
            }
            counter = 0;
        }
    }
    return "";

}
Team::~Team()
{
    PlayerNode* current = head;
    while( current != NULL )
    {
        PlayerNode* next = current->next;
        delete current;
        current = next;
    }
    head = 0;
}



