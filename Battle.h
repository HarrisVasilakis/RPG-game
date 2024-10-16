#ifndef BATTLE_H
#define BATTLE_H

#include "Monster.h"
#include "Living.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Battle
{
    private:
        vector <Monster*> RoundsMonster;
    public:
        Battle();
        ~Battle();
        void GamePlay(vector <Hero*>& MyHeroes);
        bool RoundEnd(Hero*);
		void attack(Hero*, Monster*);
		void attack(Monster*, Hero*);
        void castSpell(Hero*, Monster*);
        void use(Hero*);
        bool alive( bool *arr, int sizearr );
        void equip(Hero*);
        void displayStats(vector <Hero*>& MyHeroes);
};

#endif // BATTLE_H
