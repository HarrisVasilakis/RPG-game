#include "Living.h"
#include <iostream>
#include <cstring>

#define hlp 10

using namespace std;

Living::Living(string nam, int lev, int hp): name(nam), level(lev), healthPower(hp)
{
}

Living::~Living()
{
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

Hero::Hero(string nam, int lev, int hp): Living(nam, lev, hp)
{
    magicPower = 10;
    strength = 2;
    dexterity = 2;
    agility = 2;
    money = 10;
    experience = 0;
}

Hero::~Hero()
{
}

void Hero::printStats()
{
	cout << "Name : " << this->get_name() << ",  Level : " << this->get_level() << ",  Healthpower : " << this->get_healthPower() <<endl;
	cout << "Magicpower : " << this->get_magicPower() << ",  Strength : " << this->get_strength() << ",  Dexterity : " << this->get_dexterity();
	cout << ",  Agility : " << this->get_agility() << ",  Money : " << this->get_money() << ", Experience : " << this->get_experience() << endl;
	if(this->get_rightHand()!=NULL)
		cout << "Right hand : " << this->get_rightHand()->get_name(); 
	if(this->get_leftHand()!=NULL)
		cout << ",  Left hand : " << this->get_leftHand()->get_name() << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

Warrior::Warrior(string nam, int lev): Hero(nam, lev, hlp)
{
    this->set_strength(2);
    this->set_agility(2);
}

Warrior::~Warrior()
{
}

void Warrior::levelUp()
{
    this->set_strength(3);
    this->set_dexterity(2);
    this->set_agility(3);
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

Sorcerer::Sorcerer(string nam, int lev): Hero(nam, lev, hlp)
{
    this->set_dexterity(2);
    this->set_agility(2);
}

Sorcerer::~Sorcerer()
{
}

void Sorcerer::levelUp()
{
    this->set_strength(2);
    this->set_dexterity(3);
    this->set_agility(3);
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

Paladin::Paladin(string nam, int lev): Hero(nam, lev, hlp)
{
    this->set_strength(2);
    this->set_dexterity(2);
}

Paladin::~Paladin()
{
}

void Paladin::levelUp()
{
    this->set_strength(3);
    this->set_dexterity(3);
    this->set_agility(2);
}

