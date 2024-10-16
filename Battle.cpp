#include "Battle.h"
#include "Living.h"
#include "Monster.h"
#include "Spells.h"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

Battle::Battle()
{
}

Battle::~Battle()
{
	for(int i=0;i<RoundsMonster.size();i++){
		delete RoundsMonster[i];
	}
}

void Battle::GamePlay(vector <Hero*>& MyHeroes)
{
    int NumHer = MyHeroes.size();									
    int NumMonst = NumHer;									// The number of monsters is the same with the number of heroes. // 
    for (int i=0; i<NumMonst; i++){							//In this loop, the monsters are created and their type is chosen in random. //
        int typeOfMonster = rand() % 3 + 1;
		int monstersLevel = MyHeroes[0]->get_level(); 		//Monsters' level . //
		if (typeOfMonster == 1){							//The monsters created and added in vector of monsters. //
            Dragon *DR=new Dragon(monstersLevel);
            RoundsMonster.push_back(DR);
        }
        else if (typeOfMonster == 2){
            Exoskeleton *EX=new Exoskeleton(monstersLevel);
            RoundsMonster.push_back(EX);
        }
        else if (typeOfMonster == 3){
            Spirit *SP=new Spirit(monstersLevel);
            RoundsMonster.push_back(SP);
        }
    }
    string Turn = "Heroes";           				//This variable change (heroes-monsters) and it determines the turn on each turn. //
    string ATTKIND;									
    bool *heroeslife;								
    bool *monsterslife;	
    heroeslife = new bool [NumHer];					//This is an array of boolean variables which shows the conditon of each living. //
    monsterslife = new bool [NumMonst];
    for (int i=0; i<NumHer; i++){            		//(NumHer = NumMonst)
            heroeslife[i] = true;					// The value of true means that the livings are alive.//
            monsterslife[i] = true;
    }
    cout << "You are in a battle!" << endl;
    while (alive(heroeslife, NumHer) && alive(monsterslife, NumMonst)){			// If all the heroes and all the monsters are alive continue... //
    	cout << "turn of " << Turn << endl;
        if (Turn == "Heroes"){
			for (size_t i=0; i<MyHeroes.size(); i++){				
				if (heroeslife[i] == true){							//Each hero must be alive in order to can make these actions! //
					int MON=1;
					do{										
	            		cout << "What do you want to do (attack, castSpell, use, equip, display stats) ? " << endl;
	            		cin >> ATTKIND;
	            		if (ATTKIND == "display stats" || ATTKIND == "stats" || ATTKIND== "display" || ATTKIND == "displayStats")
						{
							this->displayStats(MyHeroes);
						}
					}while(ATTKIND != "attack" && ATTKIND != "equip" &&  ATTKIND != "castSpell" && ATTKIND != "use");
    				if (ATTKIND == "attack"){
            			cout << "Which monster ?(1-" << NumMonst << ")" << endl;
            			cin >> MON;
            			if (!( MON >= 1 && MON<=NumMonst))				//The insert value is checked to be one of the monsters. //
							MON =1;
						int reduction=0;							
						for(int k=0;k<RoundsMonster[MON-1]->get_turnescblock().size();k++){		//The amount of blocked escapechanche added to reduction .//
							reduction += RoundsMonster[MON-1]->get_escblock()[k];
						}
						if ( RoundsMonster[MON-1]->get_escapechance()-reduction < rand()%(50) ){  	//This is our way to calculate the chances of escape. //
							cout << "You hit the monster" << endl;
							this->attack(MyHeroes[i], RoundsMonster[MON-1]); 						
                    	}
						else 
							cout << "------ Attack avoided ------"	<< endl;
					}
            		else if (ATTKIND == "equip"){
            			this->equip(MyHeroes[i]);
					}
            		else if (ATTKIND == "castSpell"){
						cout << "Which monster ?1(-" << NumMonst << ")" << endl;
            			cin >> MON;
            			if (!( MON >= 1 && MON<=NumMonst))
							MON =1;
						int reduction=0;
						for(int k=0;k<RoundsMonster[MON-1]->get_turnescblock().size();k++){			//The same as before! //
							reduction += RoundsMonster[MON-1]->get_escblock()[k];
						}
						if (RoundsMonster[MON-1]->get_escapechance()-reduction < rand()%(50)){ 
							cout << "You hit the monster" << endl;   
							this->castSpell(MyHeroes[i], RoundsMonster[MON-1]);
						}
						else 
							cout << "------ Attack avoided ------"	<< endl;
					}
            		else if (ATTKIND == "use"){
            			this->use(MyHeroes[i]);
					}
                	else
                		cout << "Undefined type of attack" << endl;	
            		if (RoundsMonster[MON-1]->get_healthPower() <= 0){		//If a monster dies the value in bollean array is changed to "false" (=not alive). //
						monsterslife[MON-1] = false;
					}
            		Turn = "Monsters";
   				}
        	}
		}
        else if (Turn == "Monsters"){				//Monsters turn. //
           	for (int j=0; j<NumMonst; j++){
			   	if (monsterslife[j] == true){		//If the monster is alive , it can make these actions. //
					int op = rand() % NumHer;
					if ( heroeslife[op] ){
						if ( MyHeroes[op]->get_agility() < rand()%(50))	{	//The same with escape chanes. //
							this->attack(RoundsMonster[j],MyHeroes[op]);
							cout <<"You got hit" << endl;
						}
						else 
							cout << "------ Attack avoided ------"	<< endl;		   		
				   }
		   			else{
		   				for (int i=0; i<NumHer; i++){
		   					if (heroeslife[i]){
		   						op =i;
		   						if ( MyHeroes[op]->get_agility() < rand()%(50)){
		   							cout <<"You got hit" << endl;
								    this->attack(RoundsMonster[j],MyHeroes[op]);
									break;
								}
	   							else {
									cout << "------ Attack avoided ------"	<< endl;
									break;
								}
		   					}
						}
					}
					if (MyHeroes[op]->get_healthPower() <= 0)
                		heroeslife[op] = false;
			   	}
			}
           	Turn = "Heroes";
        }
        for ( int i=0; i<NumHer; i++){			//The health power and the magic power are increased in each round. //
        	if (heroeslife[i] == true){			//If the hero is alive...! //
        		if(MyHeroes[i]->get_healthPower()<10){
        			MyHeroes[i]->set_healthPower(1);
				}
				if(MyHeroes[i]->get_magicPower()<10){
					MyHeroes[i]->set_magicPower(1);
				}
			}
		}
		for ( int j=0; j<NumMonst; j++){		//The health power is increased in each round. //
            if (monsterslife[j] == true){		//If the monster is alive...! //
            	if(RoundsMonster[j]->get_healthPower()<10)
            		RoundsMonster[j]->set_healthPower(1);	
			}
		}
		for(int i=0; i<NumMonst; i++){			
			if (monsterslife[i] == true){		
				for(int j=0;j<RoundsMonster[i]->get_turndefblock().size(); j++){		 
            		if(RoundsMonster[i]->get_turndefblock()[j] == 0){													// If the turns which the reduction of spell is acted, is ended. //
            			RoundsMonster[i]->get_turndefblock().erase( RoundsMonster[i]->get_turndefblock().begin() + j);	//This round from turns of blocked defence vector is erased. //
            			RoundsMonster[i]->get_defblock().erase( RoundsMonster[i]->get_defblock().begin() + j);			//This amount of blocked defence vector is erased. //
					}	
				}
				for(int j=0;j<RoundsMonster[i]->get_turnescblock().size(); j++){
            		if(RoundsMonster[i]->get_turnescblock()[j] == 0){
            			RoundsMonster[i]->get_turnescblock().erase( RoundsMonster[i]->get_turnescblock().begin() + j);	
            			RoundsMonster[i]->get_escblock().erase( RoundsMonster[i]->get_escblock().begin() + j);
					}	
				}
				for(int j=0;j<RoundsMonster[i]->get_turndamblock().size(); j++){
            		if(RoundsMonster[i]->get_turndamblock()[j] == 0){
            			RoundsMonster[i]->get_turndamblock().erase( RoundsMonster[i]->get_turndamblock().begin() + j);
            			RoundsMonster[i]->get_damblock().erase( RoundsMonster[i]->get_damblock().begin() + j);
					}	
				}
			}
		}
    }
    if (alive(monsterslife, NumMonst) == false ){		//If the monsters are alive and they winned... //
    	cout << "You won!" << endl;
    	for (size_t i=0; i<MyHeroes.size(); i++){	
    		for (size_t j=0; j<RoundsMonster.size(); j ++){
    			MyHeroes[i]->set_money( 2*RoundsMonster[j]->get_level()); 			//The heroes get money according to monsters level. //
    			MyHeroes[i]->set_experience( 2*RoundsMonster[j]->get_level());		//The heroes get experience according to monsters level. //
    			if ( MyHeroes[i]->get_experience() > 2*MyHeroes[i]->get_level())	//Check for heroes in order to go to the next level . //
					MyHeroes[i]->levelUp();
			}
			
		}	
	}
	else {
		cout << "You lost!" << endl;
		for (size_t i=0; i<MyHeroes.size(); i++){
			MyHeroes[i]->set_money(-MyHeroes[i]->get_money()/2);					//The heroes lose money because of their defeat. //
			MyHeroes[i]->set_healthPower(-MyHeroes[i]->get_money()/2);				//The heroes lose health power. //
		}
	}
}

void Battle::attack(Hero* hero, Monster *monster)			//For heroes //
{
    int totalDamage;
	if ( hero->get_leftHand() != NULL ){											//	If there is a weapon ... //
		totalDamage = hero->get_leftHand()->get_damage() + hero->get_strength();	// TotalDamage = damage of weapon + strength of hero. //
		int reduction=0;
		for(int i=0;i<monster->get_defblock().size();i++){							
			reduction+= monster->get_defblock()[i];									//Added the the blocked - defence to the reduction. //
		}
    	totalDamage -= monster->get_defence() - reduction;
	}
    else
    	totalDamage =0;
    totalDamage=-totalDamage;
    
    if ( totalDamage < 0)
    	monster->set_healthPower(totalDamage);
}

void Battle::castSpell(Hero* hero, Monster* monster)
{
	bool bl = false;
	do {
	string sp;
	cout << "Give Spell !!!!!" << endl;//na valoume to minlevel kai meiwsh magicpower
	cin >> sp;
	for(int i=0;i<hero->get_spells().size();i++){
		if(hero->get_spells()[i]->get_name() == sp){
			if (hero->get_spells()[i]->type_of_spell() == "IceSpell"){				
				monster->set_damblock(hero->get_spells()[i]->get_reduction());				//Push back to Blocked- damage vector the amount of this spell which is chosen . //
				monster->set_turndamblock(hero->get_spells()[i]->get_turnsnum());			//Push back to Turns of Blocked-damge vector the turns which act this spell. //
			}
			else if (hero->get_spells()[i]->type_of_spell() == "FireSpell"){
				monster->set_defblock(hero->get_spells()[i]->get_reduction());
				monster->set_turndefblock(hero->get_spells()[i]->get_turnsnum());
			}
			else if (hero->get_spells()[i]->type_of_spell() == "Lighting"){
				monster->set_escblock(hero->get_spells()[i]->get_reduction());
				monster->set_turnescblock(hero->get_spells()[i]->get_turnsnum());
			}
			hero->set_magicPower(-hero->get_spells()[i]->get_minEnergy());
			int defreduction=0;
			for(int k=0;k<monster->get_defblock().size();k++){
				defreduction+=monster->get_defblock()[k];
			}
			int totalDamage = hero->get_spells()[i]->get_damRange() + hero->get_dexterity();
			totalDamage = totalDamage -(monster->get_defence()-defreduction);
    		if ( totalDamage > 0)
    			monster->set_healthPower(-totalDamage);
		}
		else{
			cout << "Invalid type of spell" <<endl;
			bl = true;
		} 
	}
	}while(bl);
	
}

void Battle::use(Hero* hero)
{
	bool bl = false;
	do {
	string sp;
	cout << "Give Potion !!!!" <<endl;
	cin >> sp;
	for(int i=0;i<hero->get_potions().size();i++){
		if(hero->get_potions()[i].get_name() == sp){
			if( hero->get_potions()[i].get_minlevel() <= hero->get_level() ){
				if ( hero->get_potions()[i].get_stat() == "magicPower" )
					hero->set_magicPower( hero->get_potions()[i].get_plus());
				else if ( hero->get_potions()[i].get_stat() == "strength" )
					hero->set_strength( hero->get_potions()[i].get_plus());
				else if ( hero->get_potions()[i].get_stat() == "dexterity" )
					hero->set_dexterity( hero->get_potions()[i].get_plus());
				else if ( hero->get_potions()[i].get_stat() == "agility" )
					hero->set_agility( hero->get_potions()[i].get_plus());
				else if ( hero->get_potions()[i].get_stat() == "healthPower" ){
					hero->set_healthPower( hero->get_potions()[i].get_plus());
				}
				hero->get_potions().erase(hero->get_potions().begin() + i);
				break;
			}
		}
	}
	}while(bl);	
}

void Battle::equip(Hero* hero)
{
	string b;
	int i=0;
	cout << "Do you want to equip an armor "  << endl;
	cin >> b;
	cout << endl;
	if(b=="yes" || b=="y"){
		cout << "Which one do you choose?" << endl;
		cin >> b;
		cout << endl;
		for(int j=0;hero->get_armor().size();j++){
			if(hero->get_armor()[j].get_name()==b){
				if(hero->get_leftHand()!=NULL && hero->get_leftHand()->get_doublehanded()){
					cout << "Can't equip because you hold double handed weapon" << endl;
				}
				else{
					hero->set_rightHand(&hero->get_armor()[j]);
					break;
				}
			}
		}
	}
	cout << "Do you want to equip a weapon ? " << endl;
	cin >> b;
	cout << endl;
	if(b=="yes" || b=="y"){
		cout << "Which one do you choose?" << endl;
		cin >> b;
		cout << endl;
		for(int j=0;hero->get_weapons().size();j++){
			if(hero->get_weapons()[j].get_name()==b){
					hero->set_leftHand(&hero->get_weapons()[j]);
					if(hero->get_rightHand()!=NULL && hero->get_leftHand()->get_doublehanded()){
						hero->set_rightHand(NULL);
					}
					break;
			}
		}
	}
}

void Battle::displayStats(vector <Hero*>& MyHeroes)
{
	for (int i=0; i<MyHeroes.size(); i++){
		cout << "Hero " << i+1 <<endl;
		MyHeroes[i]->printStats();
	}
	for (int i=0; i<RoundsMonster.size(); i++){
		cout << "Monster " << i+1 <<endl;
		RoundsMonster[i]->printStats();
	}
}

void Battle::attack(Monster *monster, Hero* hero)					//For monsters //
{
   	int totalDamage;
	if ( hero->get_rightHand() != NULL){							//The opposite of function attack (for heroes) . //
	   	totalDamage = monster->get_damage() - hero->get_rightHand()->get_damagereduction();	   	
	}
	else{
		totalDamage = monster->get_damage();
	}
    if ( totalDamage > 0){
    	hero->set_healthPower(-totalDamage);
	}
}


bool Battle::alive( bool *life, int sizearr)
{
    int died = 0;
    for (int i=0; i<sizearr; i++){
        if (life[i] == false )
            died ++;
    }
    if (died == sizearr)
        return false;
    else
        return true;
}
