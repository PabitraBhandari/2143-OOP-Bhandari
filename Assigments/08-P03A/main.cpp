/*******************************************************
*
*  Author:           Prakash Tamang, Pabitra Bhandari
*  Email:            pratmg2@gmail.com, pabitrabhandari19@gmail.com
*  Label:            P03A
*  Title:            Rock Paper Scissors Lizard Spock
*  Course:           CMPS 2143
*  Semester:         Fall 2021
*
*  Description:
*        This is programming of a game (Rock, Paper, Scissors, Lizard, Spock) RPSLS played by 2 players with 
*   two different random weapons. The emojis are weapons represented by rock, paper, scissors, lizard, and spock. 
*
* The rules for the game are given below:
*            Scissors cuts Paper
*            Paper covers Rock
*            Rock crushes Lizard
*            Lizard poisons Spock
*            Spock smashes Scissors
*            Scissors decapitates Lizard
*            Lizard eats Paper
*            Paper disproves Spock
*            Spock vaporizes Rock
*            Rock crushes Scissors
*
*
*  Usage:
*       to compile and run game
*
*  Files:
*       main.cpp        : driver program
*       RockPaper.hpp   : implementation of game
*       output.txt      : output of program
************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "RockPaper.hpp"

using namespace std;

int main()
{
    for (int i = 1; i <= 1; i++)
    {
        cout << "Instance " << i << endl;
        Player p1;
        Player p2;

        cout << "Player 1's weapons: " << p1.weapon1 << " " << p1.weapon2 << endl;
        cout << "Player 2's weapons: " << p2.weapon1 << " " << p2.weapon2 << endl;

        battle(p1, p2);
    }
}

