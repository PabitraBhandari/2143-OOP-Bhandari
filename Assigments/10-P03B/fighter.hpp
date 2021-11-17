#include <iostream>
#include <string>
#include "weapon.hpp"

using namespace std;

/**
 * class BaseFighter
 * 
 * Description:
 *      Creates base fighter type and assigns name and weapon to specified fighter type.
 * 
 * Public Methods:
 *    double health;
 *    double regenRate;    
 *    Primary weapon (Fist and Feet);
 * 
 *    
 */


class BaseFighter                                 // Creates base fighter type
{
    public:
        BaseFighter()
        {
                                                  // Base stats on every fighter
            health = rand()%5 + 3;
            regenRate = (rand()%60 + 15)/100;
        }

        double health;
        double regenRate;

        Weapon useWeapon;

        string name;
};

// Assigns name and weapon to Warrior
class Warrior : public BaseFighter
{
    public:
        Warrior()
        {
            useWeapon = Sword();
            name = "Warrior";
        }
};

// Assigns name and weapon to Wizard
class Wizard : public BaseFighter
{
    public:
        Wizard()
        {
            useWeapon = MagicSpell();
            name = "Wizard";
        }
};

// Assigns name and weapon to Archer
class Archer : public BaseFighter
{
    public:
        Archer()
        {
            useWeapon = Bow();
            name = "Archer";
        }
};

// Assigns name and weapon to Elf
class Elf : public BaseFighter
{
    public:
        Elf()
        {
            useWeapon = MagicSword();
            name = "Elf";
        }
};

// Assigns name and weapon to DragonBorn
class DragonBorn : public BaseFighter
{
    public:
        DragonBorn()
        {
            useWeapon = FireBow();
            name = "Dragon Born";
        }
};
