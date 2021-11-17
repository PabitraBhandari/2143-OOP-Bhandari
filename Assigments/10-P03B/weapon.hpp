#include <iostream>
#include <vector>
#include <string>
#include "dice.hpp"

using namespace std;
/**
 * class Weapon
 * 
 * Description:
 *      This class creates a base class for fist and feet weapon, or generates
        a weapon based on random and sub classes virtually inheirits from base class.
 * 
 * Public Methods:
      int useRand;
      attackValue;
 * 
 * 
 */

// Creates Base class for weapon and generates base value "fists and feet"
class Weapon
{
    public:
        Weapon()
        {
            
            int useRand = rand()%2;             // Random dice values

            if(useRand)
            {
                attackValue = Dice("1d6");
            }
            else
            {
                attackValue = Dice("1d4");
            }
        }
    
    Dice attackValue;
};

// Creates sword class that inheirits virtually from weapon
class Sword : virtual public Weapon
{
    public:
        Sword()
        {
            int useRand = rand()%3;
            
            if(useRand == 2)
            {
                attackValue = Dice("3d4");
            }
            else if(useRand == 1)
            {
                attackValue = Dice("2d6");
            }
            else
            {
                attackValue = Dice("1d12");
            }
        }
    
};

// Creates Bow class that inheirits virtually from weapon
class Bow : virtual public Weapon
{
    public:
        Bow()
        {
            int useRand = rand()%3;
            
            if(useRand == 2)
            {
                attackValue = Dice("1d8");
            }
            else if(useRand == 1)
            {
                attackValue = Dice("2d4");
            }
            else
            {
                attackValue = Dice("1d10");
            }
        }
    
};

// Creates MagicSpell class that inheirits virtually from weapon
class MagicSpell : virtual public Weapon
{
    public:
        MagicSpell()
        {
            int useRand = rand()%4;
            
            if(useRand == 3)
            {
                attackValue = Dice("1d20");
            }
            else if(useRand == 2)
            {
                attackValue = Dice("2d10");
            }
            else if(useRand == 1)
            {
                attackValue = Dice("3d6");
            }
            else
            {
                attackValue = Dice("5d4");
            }
        }
};

// Creates MagicWeapon class that inheirits virtually from weapon
class MagicWeapon : virtual public Weapon
{
    public:
        MagicWeapon()
        {
            int useRand = rand()%2;

            if(useRand)
            {
                attackValue = Dice("1d6");
            }
            else
            {
                attackValue = Dice("1d4");
            }
        }
};

// Creates FireWeapon class that inheirits virtually from weapon
class FireWeapon : virtual public Weapon 
{
    public:
        FireWeapon()
        {
            int useRand = rand()%2;

            if(useRand)
            {
                attackValue = Dice("1d6");
            }
            else
            {
                attackValue = Dice("1d8");
            }
        }
};
/**
 * class MagicSword
 * 
 * Description:
 *      Creates weapon type that inheirits virtually from both weapon and weapon type
 * 
 */
class MagicSword : virtual public Sword, virtual public MagicWeapon
{
     public:
        MagicSword()
        {
            Weapon::attackValue = Sword::attackValue + MagicWeapon::attackValue;
        }
};

/**
 * class FireSword
 * 
 * Description:
 *      Creates weapon type that inheirits virtually from both weapon and weapon type
 * 
 */
class FireSword : virtual public Sword, virtual public FireWeapon
{
     public:
        FireSword()
        {
            Weapon::attackValue = Sword::attackValue + FireWeapon::attackValue;
        }
};

/**
 * class MagicBow
 * 
 * Description:
 *      Creates weapon type that inheirits virtually from both weapon and weapon type
 * 
 */
class MagicBow : virtual public Bow, virtual public MagicWeapon
{
     public:
        MagicBow()
        {
            Weapon::attackValue = Bow::attackValue + MagicWeapon::attackValue;
        }
};

/**
 * class FireBow
 * 
 * Description:
 *      Creates weapon type that inheirits virtually from both weapon and weapon type
 * 
 */
class FireBow : virtual public Bow, virtual public FireWeapon
{ 
     public:
        FireBow()
        {
            Weapon::attackValue = Bow::attackValue + FireWeapon::attackValue;
        }
};
