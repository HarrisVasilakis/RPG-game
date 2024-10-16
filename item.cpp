#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

item::item(string n):name(n){                //depending the name I create a different sword,armor or potion
	if(name=="straightsword" || name=="spear" || name=="axe"){
		price=2;
		minlevel=1;
	}
	else if(name=="greatsword"){
		price=6;
		minlevel=5;
	}
	else if(name=="katana"){
		price=7;
		minlevel=6;
	}
	else if(name=="hammer"){
		price=7;
		minlevel=6;
	}
	else if(name=="widow_maker"){
		price=8;
		minlevel=8;
	}
	else if(name=="leather"){
		price=2;
		minlevel=1;
	}
	else if(name=="wooden"){
		price=4;
		minlevel=3;
	}
	else if(name=="steel"){
		price=6;
		minlevel=6;
	}
	else if(name=="stone"){
		price=8;
		minlevel=9;
	}
	else if(name=="nettle"){
		price=10;
		minlevel=10;
	}
	else if(name=="health_potion" || name=="magic_potion"){
		price=2;
		minlevel=1;
	}
	else if(name=="spinach" || name=="dope" || name=="cocaine"){
		price=5;
		minlevel=5;
	}
	else if(name=="super_health_potion" || name=="super_magic_potion"){
		price=4;
		minlevel=5;
	}
}
item::~item(){
}

int item::get_minlevel(){
	return minlevel;
}

int item::get_price(){
	return price;
}

string item::get_name(){
	return name;
}

weapon::weapon(string n):item(n){
	if(n=="straightsword" || n=="axe"){
		damage=2;
		doublehanded=false;
	}
	else if(n=="spear"){
		damage=3;
		doublehanded=true;
	}
	else if(n=="greatsword"){
		damage=6;
		doublehanded=true;
	}
	else if(n=="hammer"){
		damage=9;
		doublehanded=true;
	}
	else if(n=="katana"){// se periptwsh pou allajh timh xreiazetai ki allagh sto menu//
		damage=6;
		doublehanded=false;
	}
	else if(n=="widow_maker"){
		damage=8;
		doublehanded=false;
	}
}
weapon::~weapon(){
}

int weapon::get_damage(){
	return damage;
}

bool weapon::get_doublehanded(){
	return doublehanded;
}

void weapon::printinfo(){                     //print all info of weapon
	cout << this->get_name() << "(selling price=" << this->get_price()/2 << " coins, minimum levels requiored=" << this->get_minlevel() << ",damage=" << this->get_damage() << ",hands to wield=" << this->get_doublehanded()+1 << ")" << endl;
}


armor::armor(string n):item(n){
	if(n=="leather"){
		damagereduction=1;
	}
	else if(n=="wooden"){
		damagereduction=2;
	}
	else if(n=="steel"){
		damagereduction=4;
	}
	else if(n=="stone"){
		damagereduction=10;
	}
	else if(n=="nettle"){
		damagereduction=-1;
	}
	cout<<  n <<" created" << endl;
}
armor::~armor(){
	cout << "Armor destroyed" << endl;
}

int armor::get_damagereduction(){
	return damagereduction;
}

void armor::printinfo(){           //print info of armor
	cout << this->get_name() << "(selling price=" << this->get_price()/2 << " coins, minimum levels requiored=" << this->get_minlevel() << ",it protects from " << this->get_damagereduction() << " damage)" << endl;
}

potions::potions(string n):item(n){
	if(n=="health_potion"){
		stat="healthPower";
		plus=2;
	}
	else if(n=="magic_potion"){
		stat="magicPower";
		plus=2;
	}
	else if(n=="spinach"){
		stat="strength";
		plus=3;
	}
	else if(n=="cocaine"){
		stat="dexterity";
		plus=3;
	}
	else if(n=="dope"){
		stat="agility";
		plus=3;
	}
	else if(n=="super_health_potion"){
		stat="healthPower";
		plus=6;
	}
	else if(n=="super_magic_potion"){
		stat="magicPower";
		plus=6;
	}
}
potions::~potions(){
}

int potions::get_plus(){
	return plus;
}

string potions::get_stat(){
	return stat;
}

void potions::printinfo(){          //print info of potion
	cout << this->get_name() << "(selling price=" << this->get_price()/2 << " coins, minimum levels requiored=" << this->get_minlevel() << " and increases " << this->get_stat() << " by " << this->get_plus() << ")" << endl;
}
