#ifndef MONSTER_H
#define MONSTER_H

#include "Living.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Monster: public Living{
	private:
        int minDamageRange;
        int maxDamageRange;
        int defence;
        int escapechance;
		vector <int> defblock;
		vector <int> turndefblock;
		vector <int> escblock;
		vector <int> turnescblock;
		vector <int> damblock;
		vector <int> turndamblock;
	public:
		Monster(string nam, int &lev, int hp);
		~Monster();
		void set_damage(int dam){ minDamageRange +=dam; maxDamageRange +=dam;}
		void set_defence(int def){ defence +=def; }
		void set_escapechance(int esc){ escapechance +=esc; }
		int get_damage();
		int get_defence(){ return defence; }
		int get_escapechance(){ return escapechance; }
		int get_minDamageRange(){ return minDamageRange; }
        int get_maxDamageRange(){ return maxDamageRange; }
        void printStats();
		vector <int>& get_defblock(){return defblock;}
		vector <int>& get_turndefblock(){return turndefblock;}
		vector <int>& get_escblock(){return escblock;}
		vector <int>& get_turnescblock(){return turnescblock;}
		vector <int>& get_damblock(){return damblock;}
		vector <int>& get_turndamblock(){return turndamblock;}
		void set_defblock(int df){defblock.push_back(df);}
		void set_turndefblock(int trdf){turndefblock.push_back(trdf);}
		void set_escblock( int es){escblock.push_back(es);}
		void set_turnescblock( int tres){turnescblock.push_back(tres);}
		void set_damblock( int dm ){damblock.push_back(dm);}
		void set_turndamblock( int trdm){turndamblock.push_back(trdm);}
};


class Dragon: public Monster{
	public:
		Dragon(int lev);
		~Dragon();
};


class Exoskeleton: public Monster{
	public:
		Exoskeleton(int lev);
		~Exoskeleton();
};


class Spirit: public Monster{
	public:
		Spirit(int lev);
		~Spirit();
};

#endif // MONSTER_H
