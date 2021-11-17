#include <iostream>
#include <vector>
#include <string>


using namespace std;

#pragma once

/**
 * class Die
 * 
 * Description:
 *      This class creates a dice or it passes one in
 * 
 * Public Methods:
 *      die()
        die(int sides)
        int roll(int rolls)
 * 
 *      
 */

class Die 
{
	int sides;
public:

	Die(int sidesIn = 6)
    {
		sides = sidesIn;
	}
	int roll(int rolls = 1) 
    {
			int sum = 0;
			while(rolls--)
            {
				sum += (rand() % sides) + 1;
			}
			return sum;
	};

	friend ostream& operator<<(ostream &os, const Die& d)
    {
			return os << "[" << d.sides << "]";
	}
};


/**
 * class Dice
 * 
 * Description:
 *      This class creates a dice and sets value.
 * 
 * Public Methods:
 *      setstrings;
 *      diceString;
 * 
 *      
 */


class Dice
{
	public:
    string setString;

	Dice(string diceString = "1d6")
    {
		setString = diceString;
	}
	int roll()
    {
		int index = 0;
		char mode = 's';
	
		if(setString[0] == 'a' || setString[0] == 'b')
        {
			mode = setString[0];
			index = 1;
		}

		string count = "0", sides = "0", base = "0";
		while(setString[index] != 'd' && index < setString.size())
        {
			count += setString[index];
			index++;
		}
		index++;
		while(setString[index] != '+' && index < setString.size())
        {
			sides += setString[index];
			index++;
		}
		index++;
		while(index < setString.size())
        {
			base += setString[index];
			index++;
		}
		if(mode == 'a')
        {
			return average(stoi(count),stoi(sides),stoi(base));
		} 
        else if(mode == 'b')
        {
			return bestOf(stoi(count),stoi(sides),stoi(base));
		} 
        else 
        {
			return standard(stoi(count),stoi(sides),stoi(base));
		}
	}

	int standard(int count,int sides,int base)
    {
		int result = 0;
		for(int i = 0; i < count; i++)
        {
			result += (rand() % sides) + 1;
		}
		return result + base;
	}
	int average(int count,int sides,int base)
    {
		int result = 0;
		for(int i = 0; i < count; i++)
        {
			result += (rand() % sides) + 1;
		}
		return (result / count) + base;
	}
	int bestOf(int count,int sides,int base)
    {
		int result = 0;
		for(int i = 0; i < count; i++)
        {
			int dieRoll = (rand() % sides) + 1;
			if(result < dieRoll)
            { 
				result = dieRoll;
			}
		}
		return result + base;
	}

    const Dice operator+(Dice rhs)      // Adds two dice together
    {
        string newDiceString;
        Dice returnVal;
        string constant;


        if(setString.find('+') != string::npos)
        {
            int constant = stoi(setString.substr(setString.find('+'),string::npos));
            string sWithouta = setString.substr(0, setString.find('+'));
            returnVal = Dice(sWithouta + "+" + to_string(rhs.roll() + constant));
            return returnVal;
        }
      
        else
        {
            newDiceString = setString + "+" + to_string(rhs.roll());

            returnVal = Dice(newDiceString);
            return returnVal;
        }
    }
};
