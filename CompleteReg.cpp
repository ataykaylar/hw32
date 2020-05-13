#include "CompleteReg.h"
#include <iostream>
using namespace std;

CompleteReg::CompleteReg()
{
    head = NULL;
    teamCount = 0;
}

CompleteReg::CompleteReg ( const CompleteReg &systemToCopy ):teamCount(systemToCopy.teamCount)
{
    if (systemToCopy.head == NULL)
        head = NULL;
    else
    {
        head = new Node;
        head->t = systemToCopy.head->t;
        Node *newPtr = head;
        for (Node *origPtr = systemToCopy.head->next;
                origPtr != NULL;
                origPtr = origPtr->next)
        {
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->t = origPtr->t;
        }
        newPtr->next = NULL;
    }
}

CompleteReg& CompleteReg::operator=( const CompleteReg &right )
{

    if( this != &right )
    {
        teamCount = right.teamCount;
        Node* cur = head;
        while(cur != NULL)
        {
            Node* temp = cur-> next;
            delete cur;
            cur = temp;
        }

        head = new Node();
        head->t = right.head->t;
        cur = head;

        for( Node* i = right.head -> next; i != NULL; i = i->next )
        {
            Node* ptr = new Node();
            ptr->t = i->t;
            cur ->next = ptr;
            cur = cur->next;
        }
        cur->next = NULL;
    }
    return *this;
}


Team& CompleteReg::operator[]( const int index )
{
    if( index > teamCount )
    {
        cout << "Index out of bounds" <<endl;

    }
    else
    {
        Node *ptr = head;
        for (int i = 0; i < index; i++)
        {
            if(ptr!=NULL)
                ptr = ptr->next;
        }

        return (ptr->t);

    }
    cout << "Index out of bounds, team in the head will be displayed" <<endl;
    return head->t;

}



void CompleteReg::addTeam( const string tName, const string tColor, const int tyear )
{
    Node *newPtr = new Node;
    Node *cur = findTeam(tName);
    (newPtr -> t).setName(tName);
    (newPtr -> t).setColor(tColor);
    (newPtr -> t).setYear(tyear);

    if(tyear < 1800 || tyear > 2020)
        cout << "Please enter a valid year"<<endl;
    else if(cur != NULL)
    {
        cout << "Please enter a unique team!" << endl;
    }
    else if(head == NULL)
    {
        head = newPtr;
        newPtr->next = NULL;
        teamCount++;
        return;
    }
    else if(ifStringsEqual(tName,0) == "")
    {
        for(Node *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if(ptr->next == NULL)
            {
                ptr->next = newPtr;
                newPtr->next = NULL;
                teamCount++;
                return;

            }
        }
    }

}

void CompleteReg::removeTeam( const string teamName )
{
    Node *deletePtr = findTeam(teamName);
    Node *prev;
    if(ifStringsEqual(teamName, 1) == "" )
    {
        cout << "Please enter a existing team name!" << endl;
        return;
    }
    if(ifStringsEqual(teamName, 1) != "")
    {
        string temp = ifStringsEqual(teamName, 1);
        deletePtr = findTeam(temp);
    }
    if((deletePtr->t).getName() == (head->t).getName())
    {
        prev = head;
        prev = head->next;
        head->next = NULL;
        head = prev;
        teamCount--;
    }
    else
    {
        for(Node *ptr = head; ptr != NULL; ptr = ptr->next)
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
        teamCount--;
    }

}


void CompleteReg::displayAllTeams() const
{
    for(Node *printPtr = head; printPtr!=NULL; printPtr = printPtr->next)
        cout << "Team: "<< (printPtr->t).getName() << " Color: "<< printPtr->t.getColor() << " Year: " <<printPtr->t.getYear()<<endl;
    if(head == NULL)
    {
        cout <<"-EMPTY-"<<endl;
    }

}

void CompleteReg::addPlayer( const string tName, const string pName, const string pPosition )
{

    for(Node *ptr = head; ptr!=NULL; ptr = ptr->next)
    {
        if(ptr->t.getName() == tName)
        {
            ptr->t.addPlayer(pName, pPosition);
            return;
        }
    }
    cout <<"Team does not exist"<<endl;
}

void CompleteReg::removePlayer( const string teamName, const string playerName )
{
    for(Node *ptr = head; ptr!=NULL; ptr = ptr->next)
    {
        if(ptr->t.getName() == teamName)
        {
            ptr->t.removePlayer(playerName);
            return;
        }
    }
    cout <<"Team does not exist"<<endl;

}
void CompleteReg::displayTeam( const string teamName ) const
{
    for(Node *ptr = head; ptr!=NULL; ptr= ptr->next)
    {
        if(ptr->t.getName() == teamName)
        {
            cout << ptr->t.getName() <<", "<<ptr->t.getColor()<<", "<< ptr->t.getYear()<<endl;
            ptr->t.displayAllPlayers();
            return;
        }
    }
}
void CompleteReg::displayPlayer( const string playerName ) const
{
    cout << playerName<<endl;
    int counter = 0;
    for(Node *ptr = head; ptr!=NULL; ptr = ptr->next)
    {
        if(ptr->t.getPlayerInfo(playerName))
        {
            ptr->t.getPrintPlayerInfo(playerName);
            counter++;
        }
    }
    if(counter == 0)
    {
        cout<<"--EMPTY--"<<endl;
    }

}


CompleteReg::Node *CompleteReg::findTeam(const string teamName) const
{
    for (Node *skip = head ; skip != NULL; skip = skip->next)
    {
        if(skip->t.getName() == teamName )
            return skip;
    }

    return NULL;
}


string CompleteReg::ifStringsEqual(const string string_1, const bool func) const
{
    unsigned int counter = 0;
    for(Node *lowPtr = head; lowPtr !=NULL ; lowPtr = lowPtr->next)
    {
        if((lowPtr->t).getName().size() == string_1.size())
        {
            for(unsigned int i = 0; i < string_1.size(); i++)
            {
                if(tolower(string_1[i]) == tolower((lowPtr->t).getName()[i]))
                {
                    counter++;

                }
                if(counter == string_1.size() && func == 0)
                {
                    cout << "Please enter a unique team for " << string_1<<endl;
                    return string_1;
                }

                if(counter == string_1.size() && func == 1)
                {
                    return lowPtr->t.getName();
                }
            }
            counter = 0;
        }
    }
    return "";
}


CompleteReg::~CompleteReg()
{
    Node* current = head;
    while( current != NULL )
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = 0;
}


