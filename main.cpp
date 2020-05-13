#include <iostream>
#include "Team.h"
#include "Player.h"
#include "CompleteReg.h"
using namespace std;
int main()
{
    CompleteReg reg;
    CompleteReg reg2;
    CompleteReg reg3;
    reg.addTeam("Team 1","Red", 2020);
    reg.addTeam("Team 2","Blue" ,1906);
    reg.addTeam("Team 3","Green" ,1906);
    reg.addTeam("Team 4","Green" ,1906);
    reg2.addTeam("Team 5","SARI", 2020);
    reg2.addTeam("Team 6","KIRMIZI" ,1932);
    reg2.addTeam("Team 7","SIYAH" ,1966);

   reg.addPlayer("Team 1", "Mahmut", "misyoner");
   reg.addPlayer("Team 1", "Ali", "saxo");
   reg.addPlayer("Team 2", "Ali", "safdgdxo");
   // reg.addPlayer("Team 1", "ALi", "saxo");
   // reg.addPlayer("Team 1", "Veli", "reverse cowgirl");
    //reg.removePlayer("Team 1", "VE");
   // reg.displayTeam("Team 1");

    reg.displayAllTeams();
    reg.displayTeam(reg[10].getName());
    reg.displayPlayer("Ayse");
    reg.displayPlayer("Ali");
    //cout << reg2.teamCount<<endl;




    return 0;

}
