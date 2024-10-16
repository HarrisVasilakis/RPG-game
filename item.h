#include<iostream>
#include<cstring>

using namespace std;

class item{
	string name;
	int price,minlevel;   //min level=level required
	public:
		item(string n);
		~item();
		int get_price();
		int get_minlevel();
		string get_name();
		virtual void printinfo()=0;
};

class weapon:public item{
	int damage;                  //damage that deals to the opponent
	bool doublehanded;
	public:
		weapon(string n);
		~weapon();
		int get_damage();
		bool get_doublehanded();
		void printinfo();
};

class armor:public item{
	int damagereduction;          //how much damage the armor absorbs      
	public:
		armor(string n);
		~armor();
		int get_damagereduction();
		void printinfo();
};

class potions:public item{
	int plus;                 // how much it increases
	string stat;              //which statistic of the hero affects
	public:
		potions(string n);
		~potions();
		int get_plus();
		string get_stat();
		void printinfo();
};
