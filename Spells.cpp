#include "Spells.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

Spell::Spell(string n):name(n)    //depending the name I create different spells
{
	if(name=="fireball" || name=="chill" || name=="flash"){
		value=2;
		minLevel=1;
		mindam=1;
		maxdam=3;
		minEnergy=3;
	}
	else if(name=="inferno" || name=="frostbite" || name=="lightning_strike"){
		value=4;
		minLevel=3;
		mindam=2;
		maxdam=5;
		minEnergy=5;
	}
	else if(name=="eruption" || name=="avalanche" || name=="surging_soul"){
		value=7;
		minLevel=6;
		mindam=4;
		maxdam=9;
		minEnergy=8;
	}
}

Spell::~Spell()
{
}

int Spell::get_damRange(){
	return rand()%maxdam +1 +mindam;
}
int Spell::get_minEnergy(){
	return minEnergy;
}
int Spell::get_minLevel(){
	return minLevel;
}
string Spell::get_name(){
	return name;
}
int Spell::get_price(){
	return value;
}


///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

IceSpell::IceSpell(string n):Spell(n)
{
	if(n=="chill"){
		opDestRange=2;
		turnsnum=1;
	}
	else if(n=="frostbite"){
		opDestRange=4;
		turnsnum=2;
	}
	else if(n=="avalanche"){
		opDestRange=7;
		turnsnum=3;
	}
}

IceSpell::~IceSpell()
{
}

int IceSpell::get_reduction(){
	return opDestRange;
}
int IceSpell::get_turnsnum(){
	return turnsnum;
}
void IceSpell::printinfo(){    //print info of spell
	cout<< this->get_name() << "(selling price=" << this->get_price() << " coins, minimum levels required=" << this->get_minLevel() << ", damage range=" << this->get_damRange() << ",minimum magicPower required=" << this->get_minEnergy() << " and reduces opponents damage by " << this->get_reduction() << " for " << this->get_turnsnum() << " turns)" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

FireSpell::FireSpell(string n):Spell(n)
{
	if(n=="fireball"){
		opAmountOfDefense=2;
		turnsnum=1;
	}
	else if(n=="inferno"){
		opAmountOfDefense=4;
		turnsnum=2;
	}
	else if(n=="eruption"){
		opAmountOfDefense=7;
		turnsnum=3;
	}
}

FireSpell::~FireSpell()
{
}

int FireSpell::get_reduction(){
	return opAmountOfDefense;
}
int FireSpell::get_turnsnum(){
	return turnsnum;
}
void FireSpell::printinfo(){
	cout<< this->get_name() << "(selling price=" << this->get_price() << " coins, minimum levels required=" << this->get_minLevel() << ", damage range=" << this->get_damRange() << ",minimum magicPower required=" << this->get_minEnergy() << " and reduce opponents defense by " << this->get_reduction() << " for " << this->get_turnsnum() << " turns)" << endl;
}


///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

LightingSpell::LightingSpell(string n):Spell(n)
{
	if(n=="flash"){
		opPossibAvoidAttack=2;
		turnsnum=1;
	}
	else if(n=="lightning_strike"){
		opPossibAvoidAttack=4;
		turnsnum=2;
	}
	else if(n=="surging_soul"){
		opPossibAvoidAttack=7;
		turnsnum=3;
	}
}

LightingSpell::~LightingSpell()
{
}

int LightingSpell::get_reduction(){
	return opPossibAvoidAttack;
}
int LightingSpell::get_turnsnum(){
	return turnsnum;
}
void LightingSpell::printinfo(){
	cout<< this->get_name() << "(selling price=" << this->get_price() << " coins, minimum levels required=" << this->get_minLevel() << ", damage range=" << this->get_damRange() << ",minimum magicPower required=" << this->get_minEnergy() << " and reduces opponents possibility of escaping an attack by " << this->get_reduction() << " for " << this->get_turnsnum() << " turns)" << endl;
}

string LightingSpell::type_of_spell(){
	return "LightingSpell";
}

string IceSpell::type_of_spell(){
	return "IceSpell";
}

string FireSpell::type_of_spell(){
	return "FireSpell";
}

