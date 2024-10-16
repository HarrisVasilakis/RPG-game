#ifndef LIVING_H
#define LIVING_H

#include "item.h"
#include "Spells.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Living
{
    private:
        string name;
        int level;
        int healthPower;
    public:
        Living(string nam, int lev, int hp);
        virtual ~Living();
        string get_name(){ return name; }
        void set_healthPower(int hp){ healthPower =healthPower + hp;  }
        int get_healthPower(){ return healthPower; }
        int get_level(){ return level; }	///////////////////////////////
};


class Hero: public Living
{
    private:
        int magicPower;
        int strength;
        int dexterity;
        int agility;
        int money;
        int experience;
        vector <weapon> HeroesWeapons;
        vector <Spell*> HeroesSpells;
        vector <potions> HeroesPotions;
        vector <armor> HeroesArmors;
        armor* rightHand;
        weapon* leftHand;
    public:
        Hero(string nam, int lev, int hp);
        virtual ~Hero();
        virtual void levelUp() = 0;                                                    //swmaaaaaaaaaa
        void set_magicPower(int mp){ magicPower += mp; }
        void set_strength(int st){ strength += st; }
        void set_agility(int ag){ agility += ag; }
        void set_dexterity(int dx){ dexterity +=dx; }
        void set_money(int mn){ money +=mn; }
        void set_experience(int ex){ experience += ex; }
        int get_magicPower(){ return magicPower; }
        int get_experience(){ return experience; }
        int get_money(){ return money; }
        int get_strength(){ return strength; }
        int get_agility(){ return agility; }
        int get_dexterity(){ return dexterity; }
        vector <weapon>& get_weapons(){ return HeroesWeapons; }
        vector <potions>& get_potions(){ return HeroesPotions; }
        vector <Spell*>& get_spells(){ return HeroesSpells; }
        vector <armor>& get_armor(){ return HeroesArmors; }
        armor* get_rightHand(){ return rightHand; }
        weapon* get_leftHand(){ return leftHand; }
        void set_rightHand( armor* rg ){ rightHand = rg; }
        void set_leftHand( weapon* lf ){ leftHand = lf; }
        void printStats();
};


class Warrior: public Hero
{
    public :
        void levelUp();
        Warrior(string nam, int lev);
        ~Warrior();
};


class Sorcerer: public Hero
{
    public :
        void levelUp();
        Sorcerer(string nam, int lev);
        ~Sorcerer();
};


class Paladin: public Hero
{
    public :
        void levelUp();
        Paladin(string nam, int lev);
        ~Paladin();
};

#endif // LIVING_H
