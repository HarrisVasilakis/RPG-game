#include "Monster.h"
#include "Living.h"

#include <iostream>
#include <cstring>
#include <cstdlib>

#define hlp 10

using namespace std;

Monster::Monster(string nam, int &lev, int hp): Living(nam, lev, hp)
{
	minDamageRange = lev*2;
	maxDamageRange = lev*4;
    defence = lev;
    escapechance = lev;
}

Monster::~Monster()
{
}

void Monster::printStats(){
	cout <<"Name : " << this->get_name() << ", Level : " << this->get_level() << ", Health : " << this->get_healthPower() << endl;
	cout << " Defence : " << this->get_defence() << ", Escape Chance : " << this->get_escapechance() << "Minimum damage : " << this->get_minDamageRange();
	cout << " Maximum damage : " << this->get_maxDamageRange() << endl;
}

int Monster::get_damage()
{ 
	int red=0;
	for(int i=0;i<this->damblock.size();i++){
		red += this->damblock[i];
	}
	int a=this->get_maxDamageRange() - this->get_minDamageRange();
	int b=rand()%a;
	int c=b+1-red;
	return c; 
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

Dragon::Dragon(int lev): Monster("Dragon", lev, hlp)
{
	this->set_damage(2);
}

Dragon::~Dragon()
{
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

Exoskeleton::Exoskeleton(int lev): Monster("Exoskeleton", lev, hlp)
{
	this->set_defence(2);
}

Exoskeleton::~Exoskeleton()
{
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

Spirit::Spirit(int lev): Monster("Spirit", lev, hlp)
{
	this->set_escapechance(2);
}

Spirit::~Spirit()
{
}
