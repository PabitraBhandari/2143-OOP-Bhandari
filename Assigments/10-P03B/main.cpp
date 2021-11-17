/*****************************************************************************
*                    
*  Author:           Prakash Tamang, Pabitra Bhandari
*  Email:            pratmg2@gmail.com, pabitrabhandari19@gmail.com
*  Label:            PO3B
*  Title:            Fight Club
*  Course:           CMPS 2143
*  Semester:         Fall 2021
* 
*  Description:
*         This program creates the appropriate number of characters based on the input 
and proceeds to manage battles between attackers and defenders choosing the appropriate 
character to fight based on the above rules and projects the winner.
*        
*  Usage: 
*       - Input file
*       
*  Files:            
*       main.cpp     : driver program 
        dice.hpp     : rolls die based on which dice
        fighter.hpp  : hold our fighters
        weapon.hpp   : hold our weapons
        input        : input file with fighters
        output       : output file with final stats
*****************************************************************************/



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <queue>
#include <stdlib.h>
#include <cmath>
#include "dice.hpp"
#include "fighter.hpp"

using namespace std;


// Class that does game structure
class Game
{
    public:
    queue<BaseFighter> attackers;           // attackers
    vector<BaseFighter> defenders;

    Game(string fileName)                   //Fills containers and runs game
    {
        fillAttackers(fileName);
        fillDefenders();
        runGame();
    }
    void fillAttackers(string fileName)
    {
        ifstream fin;
        fin.open(fileName);

        while(!fin.eof())
        {
            string BaseFighterType;
            fin >> BaseFighterType;

            if(BaseFighterType == "warrior")
            {
                attackers.push(Warrior());
            }
            else if(BaseFighterType == "wizard")
            {
                attackers.push(Wizard());
            }
            else if(BaseFighterType == "archer")
            {
                attackers.push(Archer());
            }
            else if(BaseFighterType == "elf")
            {
                attackers.push(Elf());
            }
            else
            {
                attackers.push(DragonBorn());
            }
        }
    }
   
    void fillDefenders()   // Fills defenders based on attackers
    {
        for(int i = 0; i < ceil(attackers.size()/100.0); i++)
        {
            defenders.push_back(Warrior());
            defenders.push_back(Wizard());
            defenders.push_back(Archer());
            defenders.push_back(Elf());
            defenders.push_back(DragonBorn());
        }
    }

    //  Finds defender with matching attacker name
    int findDefender(string nameToFind, int start = 0)
    {
        for(int i = start; i < defenders.size(); i++)
        {
            if(defenders[i].name == nameToFind)
            {
                return i;
            }
        }
        if(defenders.size())
        {
            return defenders.size()-1;
        }
        else
        {
            return 0;
        }
    }

    void runGame()
    {
        BaseFighter* attacker;
        BaseFighter* defender;

        int defendersLost = 0;
        int attatckersLost = 0;
        int totalAttacks = 0;
        int numRounds = 0;
        int numDef = defenders.size();
        int numAtc = attackers.size();
        
        attacker = &(attackers.front());

        int index = findDefender((*attacker).name);
        defender = &(defenders[index]);
        
        while(!attackers.empty() && !defenders.empty())
        {
            int damageDealtDef;
            int damageDealtAtc;

            // Defender's damage
            damageDealtDef = (*attacker).useWeapon.attackValue.roll();
            

            // Attackers attack
            (*defender).health -= damageDealtDef;
            cout << "Attacking " << (*attacker).name << " attacks defending " << (*defender).name << " for " << damageDealtDef <<endl;
            
            if((*defender).health <= 0)
            {
                cout << "Defending " << (*defender).name << " has died."<<endl;
                defenders.erase(defenders.begin() + index);
                defendersLost++;

                index = findDefender((*attacker).name);
                if(defenders.size()){
                    defender = &(defenders[index]);
                }
            }

            // Swap at health 5 or less else attack
            if(defenders.size() && (*defender).health <= 4)
            {
                cout << "Defending " << (*defender).name << " swaps out."<<endl;
                index = findDefender((*attacker).name, index + 1);
                defender = &(defenders[index]);
            }
            else if (defenders.size())
            {
                damageDealtAtc = (*defender).useWeapon.attackValue.roll();
                (*attacker).health -= damageDealtAtc;
                cout << "Defending " << (*defender).name << " attacks " << (*attacker).name << " for " << damageDealtAtc << "."<<endl;
            }

            // Check if died or not
            if((*attacker).health <= 0)
            {
                cout << "Attacker " << (*attacker).name << " has died."<<endl;
                attackers.pop();
                attatckersLost++;
            }

            if(attackers.size()){
                (*attacker).health += (*attacker).regenRate;
            }

            for(int j = 0; j < defenders.size(); j++)
            {
                defenders[j].health += defenders[j].regenRate;
            }
            numRounds++;
        }

        // Final output
        if(attackers.empty())
        {
            cout << "\n\nDefenders Win\n\n";
        }
        else
        {
            cout << "\n\nAttackers win\n\n";
        }

        cout << "Total Number of Attackers: " << numAtc <<endl;
        cout << "Total Number of Defenders: " << numDef <<endl;
        cout << "Number of Rounds Completed: " << numRounds <<endl;
    } 
};

int main()
{
	srand (time(NULL));
	Game("input.dat");

    return 0;
}
