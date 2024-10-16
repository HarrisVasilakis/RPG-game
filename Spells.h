#ifndef SPELLS_H
#define SPELLS_H

#include <iostream>
#include <cstring>

using namespace std;

class Spell
{
    private :
        string name;
        int value;			//price
        int minLevel;      //level einai se int
        int mindam;	   //damage
        int maxdam;
        int minEnergy;     //magicPower usage
    public :
        Spell(string n);
        ~Spell();
        int get_price();
        string get_name();
        int get_minLevel();
        int get_damRange();
        int get_minEnergy();
        virtual void printinfo()=0;
        virtual string type_of_spell()=0;
        virtual int get_reduction()=0;
        virtual int get_turnsnum()=0;
};

class IceSpell: public Spell
{
    private :
        int opDestRange;       //damage reduced
        int turnsnum;          //for number of turns
    public :
        IceSpell(string n);
        ~IceSpell();
        int get_reduction();
        int get_turnsnum();
        void printinfo();
		string type_of_spell();
};

class FireSpell: public Spell
{
    private :
        int opAmountOfDefense;     //defence reduced
        int turnsnum;
    public :
        FireSpell(string n);
        ~FireSpell();
        int get_reduction();
        int get_turnsnum();
        void printinfo();
        string type_of_spell();
        
};

class LightingSpell: public Spell
{
    private :
        int opPossibAvoidAttack;       //escape chance reduced
        int turnsnum;
    public :
        LightingSpell(string n);
        ~LightingSpell();
        int get_reduction();
        int get_turnsnum();
        void printinfo();
        string type_of_spell();
};

#endif // SPELLS_H
