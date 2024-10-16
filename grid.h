#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>

#include"Living.h"
#include"Spells.h"
#include"Battle.h"

#define WIDTH 3
#define HEIGHT 3
#define LENGTH 4

using namespace std;

class square{
	vector<Hero*> Herospot;    //the heroes in this square
	public:
	square();
	virtual ~square();
	virtual string get_name()=0;
	inline vector<Hero*>& get_positions(){return Herospot;}
	virtual void buy()=0;
	virtual void sell()=0;
	virtual void battle_chance()=0;
};

class market:public square{
	public:
		market();
		~market();
		inline string get_name(){return " market ";}
		void buy();
		void sell();
		void battle_chance(){cout << "All the merchants are dead!";}
};

class commom:public square{
	public:
		commom();
		~commom();
		inline string get_name(){return" commom ";}
		void battle_chance();
		void buy(){cout << "There is no Market here!"; }
		void sell(){cout << "There is no Market here!"; }
		
};

class nonAccessible:public square{
	public:
		nonAccessible();
		~nonAccessible();
		inline string get_name(){return "noAccess";}
		void buy(){ cout << "Huh?!";}
		void sell(){ cout << "Nani?!";}
		void battle_chance(){ cout << "I'm a mistake";}
};

class grid{
	square* mygrid[HEIGHT][LENGTH];    //the grid
	static int i, j;                  //potition of heroes
	public:
		grid(vector<Hero*>&);
		~grid();
		inline square* get_mygrid(int i,int j){return mygrid[i][j];}
		void displayMap();
		void move(string);
		inline static int get_i(){return i;}
		inline static int get_j(){return j;}
		void checkInventory();
		void checkInventory(int);
		void use();
		bool quitGame();
		void equip();
};
