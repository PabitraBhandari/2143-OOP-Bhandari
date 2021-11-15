/*****************************************************************************
*                    
*  Author:           Prakash Tamang, Pabitra Bhandari
*  Email:            pratmg2@gmail.com, pabitrabhandari19@gmail.com
*  Label:            P03B
*  Title:            BoliNverse Fight Club
*  Course:           CMPS 2143
*  Semester:         2021 FALL
* 
*  Description:
*        This assignment is being rolled back from our initial take on the BolNiverse Fight Club.
*        
*  Usage:
*       - g++ main.cpp -o main && ./main
*       - Compile and run it.
* 
*  Files:     
*       main.cpp      : main driver program
*       output.txt    : output of program
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fighter.hpp"
#include "json.hpp"
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    BaseFighter* tank;
    BaseFighter* rambo;
    tank = new Wizard;
    rambo = new Warrior;
    tank->attack();
    

}
