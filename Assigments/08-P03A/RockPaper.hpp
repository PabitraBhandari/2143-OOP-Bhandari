#include <iostream>
#include <functional> 
#include <map>
#include <random>
#include <string>
#include <fstream>

using namespace std;

#define ROCK u8"\U0001F5FB"
#define PAPER u8"\U0001F4C3"
#define SCISSORS u8"\U0001F52A"
#define LIZARD u8"\U0001F98E"
#define SPOCK u8"\U0001F596"

/**
 * Hands
 * 
 * description: A static struct that only has references to
 *      emojis for printing out Rock Paper Scissors Lizard Spock
 * 
 * methods:
 *      string RandHand()   : returns a random hand (emoji) 
 *      string Rock()       : returns the emoji for "rock" 
 *      string Paper()      : returns the emoji for "paper" 
 *      string Scissors()   : returns the emoji for "scissors" 
 *      string Lizard()     : returns the emoji for "lizard" 
 *      string Spock()      : returns the emoji for "spock" 
 */

struct Hands
{

        static map< string, string > Emojis;            // stl map
                                                        // name  , emoji

    static map< string, string > Names;                 // stl map
                                                        // emoji  , name

    static string RandHand() {
        auto it = Emojis.begin();                       // iterator to front of map

        std::advance(it, rand() % Emojis.size());       // advance some random amnt
                                                        //   of steps

        string random_hand = it->second;                // grab emoji from map

        return random_hand;                             // return rand emoji
    }

    static string Rock()
    {
        return Emojis["rock"];
    }

    static string Paper()
    {
        return Emojis["paper"];
    }

    static string Scissors()
    {
        return Emojis["scissors"];
    }

    static string Lizard()
    {
        return Emojis["lizard"];
    }

    static string Spock()
    {
        return Emojis["spock"];
    }

    
};


// initialize static data member for
// hands struct 
map< string, string > Hands::Emojis = {
    {"rock", ROCK},
    {"paper", PAPER},
    {"scissors", SCISSORS},
    {"lizard", LIZARD},
    {"spock", SPOCK}};

// initialize static data member for
// hands struct 
map< string, string > Hands::Names = {
    {ROCK, "rock"},
    {PAPER, "paper"},
    {SCISSORS, "scissors"},
    {LIZARD, "lizard"},
    {SPOCK, "spock"}};

/**
 * Player
 *
 * Description:
 *      A struct to run the RPSLS game.
 *
 * Methods:
 *         Player()
 *
 */

struct Player{
    string weapon1;
    string weapon2;
    // other possible stuff

    /**
     * Constructor guarantees a player has two different "weapons"
     */
    Player(){
        weapon1 = Hands::RandHand();
        weapon2 = Hands::RandHand();

        while (weapon2==weapon1)
        {
            weapon2 = Hands::RandHand();
        }
    }
    // other possible methods

    Player(string weapon1, string weapon2)
    {
        this->weapon1 = weapon1;
        this->weapon2 = weapon2;
    }

 //ROCK VS OTHER
    bool rockVS(string other)
    {
        bool win = false;

        if (other == PAPER){
            win = false;  // Paper covers Rock
        }
        else if (other == SCISSORS){
            win = true;   // Rock crushes Scissors
        }
        else if (other == LIZARD){
            win = true;   // Rock crushes Lizard
        }
        else if (other == SPOCK){
            win = false;  // Spock Vaporizes Rock
        }
        return win;
    }

 //PAPER VS OTHER
    bool paperVS(string other)
    {
        bool win = false;

        if (other == ROCK){
            win = true;   // Paper covers Rock
        }
        else if (other == SCISSORS){
            win = false;  // Scissors cuts Paper
        }
        else if (other == LIZARD){
            win =false;   // Lizard eats Paper
        }
        else if (other == SPOCK){
            win = true;   // Paper disproves Spock
        }
        return win;
    }

 //SCISSORS VS OTHER
    bool scissorsVS(string other)
    {
        bool win = false;

        if (other == ROCK){
            win = false;  // Rock crushes Scissors
        }
        else if (other == PAPER){
            win = true;   // Scissors cuts Paper
        }
        else if (other == LIZARD){
            win = true;   // Scissors decapitates lizard
        }
        else if (other == SPOCK){
            win = false;  // Spock samshes Scissors
        }
        return win;
    }

 //LIZARD VS OTHER
    bool lizardVS(string other)
    {
        bool win = false;

        if (other == ROCK){
            win = false;  // Rock crushes lizard
        }
        else if (other == PAPER){
            win = true;   // Lizard eats Paper
        }
        else if (other == SCISSORS){
            win = false;  // Scissors decapitates Lizard
        }
        else if (other == SPOCK){
            win = true;   // Lizard poisons Spock
        }
        return win;
    }

 //SPOCK VS OTHER
    bool spockVS(string other)
    {
        bool win = false;

        if (other == ROCK){
            win = true; // Spock vaporizes Rock
        }
        else if (other == PAPER){
            win = false; // Paper disproves Spock
        }
        else if (other == SCISSORS){
            win = true; // Spock smashes Scissors
        }
        else if (other == LIZARD){
            win = false; // Lizard poisons Spock
        }
        return win;
    }

    bool operator==(Player &other)
    {
        return (this->weapon1 == other.weapon1) && (this->weapon2 == other.weapon2);
    }

    virtual bool operator>(Player &other)
    {
        bool result = false;

        if (*this == other)                      // all players have same weapons
        {
            result = false;
        }
        else if (this->weapon1 == other.weapon1) // again players having same 1st weapons
        {
            if (this->weapon2 == ROCK){
                result = rockVS(other.weapon2);
            }
            else if (this->weapon2 == PAPER){
                result = paperVS(other.weapon2);
            }
            else if (this->weapon2 == SCISSORS){
                result = scissorsVS(other.weapon2);
            }
            else if (this->weapon2 == LIZARD){
                result = lizardVS(other.weapon2);
            }
            else{
                result = spockVS(other.weapon2);
            }
        }
        else
        {
            if (this->weapon1 == ROCK){
                result = rockVS(other.weapon1);
            }
            else if (this->weapon1 == PAPER){
                result = paperVS(other.weapon1);
            }
            else if (this->weapon1 == SCISSORS){
                result = scissorsVS(other.weapon1);
            }
            else if (this->weapon1 == LIZARD){
                result = lizardVS(other.weapon1);
            }
            else{
                result = spockVS(other.weapon1);
            }
        }
        return result;
    }

    bool operator<(Player &other)
    {
        bool result = false;

        if (*this == other)
        {
            result = false;
        }
        else 
        {
            result = !(*this > other);
        }
        return result;
    }
};

void battle(Player p1, Player p2)
{
    if(p1 > p2)
    {
        if(p1.weapon1 != p2.weapon1)
        {
            cout << "Player 1's " << p1.weapon1 << " beat Player 2's " << p2.weapon1 << endl << endl;
        }
        else
        {
            cout << "Player 1's " << p1.weapon2 << " beat Player 2's " << p2.weapon2 << endl <<endl;
        }
    }
    else if(p1 < p2)
    {
         if(p1.weapon1 != p2.weapon1)
        {
            cout << "Player 2's " << p2.weapon1 << " beat Player 1's " << p1.weapon1 << endl << endl;
        }
        else
        {
            cout << "Player 2's " << p2.weapon2 << " beat Player 1's " << p1.weapon2 << endl << endl;
        }
    }
    else
    {
        cout << "Player 1's weapons: " << p1.weapon1 << " " << p1.weapon2 << endl;
        cout << "Player 2's weapons: " << p2.weapon1 << " " << p2.weapon2 << endl;
        cout << "It's a tie!" << endl;
    }
}

