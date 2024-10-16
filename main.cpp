#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

#include "Living.h"
#include "Monster.h"
#include "Battle.h"
#include "grid.h"

using namespace std;

int main()
{
    string NAME;
    string TYPE;
    int NUM;
    do{
    	cout << "Insert the number of heroes(maximum 3)" << endl;
    	cin >> NUM;
	}while(!(NUM>0 && NUM<4));	
    vector <Hero*> HeroVector;
    for (int   i=0; i<NUM; i++){
        cout << "Insert the name of your " << i+1 << " hero : " << endl;
        cin >> NAME;
        do{
	        cout << "Insert the type of your " << i+1 << " hero (Warrior,Sorcerer,Paladin) : " << endl;
	        cin >> TYPE;
        }while(TYPE!="Warrior" & TYPE!="Sorcerer" & TYPE!="Paladin");
        if ( TYPE == "Warrior" ){
            Warrior *temp=new Warrior(NAME, 1);
            Hero* WR=temp;
            HeroVector.push_back(WR);
        }
        else if ( TYPE == "Sorcerer" ){
            Sorcerer *temp=new Sorcerer(NAME, 1);
            Hero* SC=temp;
            HeroVector.push_back(SC);
        }
        else if ( TYPE == "Paladin" ){
            Paladin *temp=new Paladin(NAME, 1);
            Hero* PL=temp;
            HeroVector.push_back(PL);
        }
        else
            cout << "Undefined type of hero" << endl;
    }
    grid GRD(HeroVector);
    bool end=true;
    string a;                             ///starts here
    while(end){
    	if(GRD.get_mygrid(GRD.get_i(),GRD.get_j())->get_name()==" commom "){
    		GRD.get_mygrid(GRD.get_i(),GRD.get_j())->battle_chance();
		}
    	do{
    		cout << "You are in a" << GRD.get_mygrid(GRD.get_i(),GRD.get_j())->get_name() << "square" << endl;
			cout << "In this square you can 'check inventory',you can 'equip' weapons or armor, 'use' a potion, 'display the map'," << endl;
			cout << "move with 'w'(up), 'a'(left), 's'(down), 'd'(right) or 'quit' to end the game" << endl;
			if(GRD.get_mygrid(GRD.get_i(),GRD.get_j())->get_name()==" market "){
				cout << "Also you can 'buy' or 'sell' in the market" << endl;
			}
			cin >> a;
			if(a=="check" || a=="inventory" || a=="check inventory" || a=="checkInventory"){
				GRD.checkInventory();
			}
			else if(a=="equip"){
				GRD.equip();
			}
			else if(a=="use"){
				GRD.use();
			}
			else if(a=="display" || a=="map" || a=="display map" || a=="display the map" || a=="displayMap"){
				GRD.displayMap();
			}
			else if(a=="buy"){
				GRD.get_mygrid(GRD.get_i(),GRD.get_j())->buy();
			}
			else if(a=="sell"){
				GRD.get_mygrid(GRD.get_i(),GRD.get_j())->sell();
			}
			else if(a=="quit"){
				end = GRD.quitGame();
			}
		}while(a!="w" && a!="a" && a!="s" && a!="d" && a!="quit");
		if(a=="w" || a=="a" || a=="s" ||a=="d"){
			GRD.move(a);
		}
	}
    return 0;
}
