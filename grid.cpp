#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include"grid.h"

using namespace std;

int grid::i=0;

int grid::j=0;


square::square(){
}
square::~square(){
	int j=this->get_positions().size();
	for(int i=0;i<j;i++){
		delete Herospot[i];
	}
}

market::market(){
}
market::~market(){
}
void market::buy(){
	cout << "Items and spells to buy:" << endl;        
	cout << "Weapons:" << endl;
	for(int i=0;i<7;i++){
		if(i==0){
			weapon temp("straightsword");
			temp.printinfo();
		}
		else if(i==1){
			weapon temp("spear");
			temp.printinfo();
		}
		else if(i==2){
			weapon temp("axe");
			temp.printinfo();
		}
		else if(i==3){
			weapon temp("greatsword");
			temp.printinfo();
		}
		else if(i==4){
			weapon temp("hammer");
			temp.printinfo();
		}
		else if(i==5){
			weapon temp("katana");
			temp.printinfo();
		}
		else if(i==6){
			weapon temp("widow_maker");
			temp.printinfo();
		}
	}
	cout << "Armor: " << endl;
	for(int i=0;i<5;i++){
		if(i==0){
			armor temp("leather");
			temp.printinfo();
		}
		else if(i==1){
			armor temp("wooden");
			temp.printinfo();
		}
		else if(i==2){
			armor temp("steel");
			temp.printinfo();
		}
		else if(i==3){
			armor temp("stone");
			temp.printinfo();
		}
		else if(i==4){
			armor temp("nettle");
			temp.printinfo();
		}
	}
	cout << "Potions: "  << endl;
	for(int i=0;i<7;i++){
		if(i==0){
			potions temp("health_potion");
			temp.printinfo();
		}
		else if(i==1){
			potions temp("magic_potion");
			temp.printinfo();
		}
		else if(i==2){
			potions temp("spinach");
			temp.printinfo();
		}
		else if(i==3){
			potions temp("dope");
			temp.printinfo();
		}
		else if(i==4){
			potions temp("cocaine");
			temp.printinfo();
		}
		else if(i==5){
			potions temp("super_health_potion");
			temp.printinfo();
		}
		else if(i==6){
			potions temp("super_magic_potion");
			temp.printinfo();
		}
	}
	cout << "Spells: " << endl;
	for(int i=0;i<9;i++){
		if(i==0){
			Spell *temp=new FireSpell("fireball");
			temp->printinfo();
		}
		else if(i==1){
			Spell * temp=new IceSpell("chill");
			temp->printinfo();
		}
		else if(i==2){
			Spell *temp=new LightingSpell("flash");
			temp->printinfo();
		}
		else if(i==3){
			Spell *temp=new FireSpell("inferno");
			temp->printinfo();
		}
		else if(i==4){
			Spell *temp=new IceSpell("frostbite");
			temp->printinfo();
		}
		else if(i==5){
			Spell *temp=new LightingSpell("lightning_strike");
			temp->printinfo();
		}	
		else if(i==6){
			Spell *temp=new FireSpell("eruption");
			temp->printinfo();
		}
		else if(i==7){
			Spell *temp=new IceSpell("avalanche");
			temp->printinfo();
		}
		else if(i==8){
			Spell *temp=new LightingSpell("surging_soul");
			temp->printinfo();
		}
	}
	string a,b;
	int i=0;
	if(this->get_positions().size()>1){     // check what hero is buying
		cout << "For what hero are you buying this item?" << endl;
		cin >> b;
		cout << endl;
		for(int j=0;j<this->get_positions().size();j++){
			if(this->get_positions()[j]->get_name()==b){
				i=j;
				break;
			}
		}
	}
	cout << "What do you want to buy?" << endl;
	cin >> a ;
	cout << endl;
	if(a=="straightsword" || a=="spear"  || a=="axe" || a=="greatsword" || a=="hammer" || a=="katana" || a=="widow_maker"){
		weapon k(a);                                                    //create the item he wants
		if(this->get_positions()[i]->get_money()>=k.get_price()){       //check if he has the money required
			this->get_positions()[i]->set_money(-k.get_price());        //pays the money
			this->get_positions()[i]->get_weapons().push_back(k);       //takes the item
		}
	}
	else if(a=="leather" || a=="wooden" || a=="steel" || a=="stone" || a=="nettle"){
		armor k(a);
		if(this->get_positions()[i]->get_money()>=k.get_price()){
			this->get_positions()[i]->set_money(-k.get_price());
			this->get_positions()[i]->get_armor().push_back(k);
		}
	}
	else if(a=="health_potion" || a=="magic_potion" || a=="spinach" || a=="dope" || a=="cocaine" || a=="super_health_potion" || a=="super_magic_potion"){
		potions k(a);
		if(this->get_positions()[i]->get_money()>=k.get_price()){
			this->get_positions()[i]->set_money(-k.get_price());
			this->get_positions()[i]->get_potions().push_back(k);
		}
	}
	else if(a=="fireball" || a=="inferno" || a=="eruption"){
		FireSpell *k=new FireSpell(a);
		Spell *l=k;
		if(this->get_positions()[i]->get_money()>=k->get_price()){
			this->get_positions()[i]->set_money(-k->get_price());
			this->get_positions()[i]->get_spells().push_back(l);
		}
	}
	else if(a=="chill" || a=="frostbite" || a=="avalanche"){
		IceSpell *k=new IceSpell(a);
		Spell *l=k;
		if(this->get_positions()[i]->get_money()>=k->get_price()){
			this->get_positions()[i]->set_money(-k->get_price());
			this->get_positions()[i]->get_spells().push_back(l);
		}
	}
	else if(a=="flash" || a=="lightning_strike" || a=="surging_soul"){
		LightingSpell *k=new LightingSpell(a);
		Spell *l=k;
		if(this->get_positions()[i]->get_money()>=k->get_price()){
			this->get_positions()[i]->set_money(-k->get_price());
			this->get_positions()[i]->get_spells().push_back(l);
		}
	}
	else{
		return;
	}
}
void market::sell(){
	int i=0;
	string b;
	if(this->get_positions().size()>1){                          //Who is selling?
		cout << "Who wants to sell this item/spell?" << endl;
		cin >> b;
		cout << endl;
		for(int j=0;j<this->get_positions().size();j++){
			if(this->get_positions()[j]->get_name()==b){
				i=j;
				break;
			}
		}
	}
	cout << "Weapons:" << endl;                                            //print inventory of hero
	for(int j=0;j<this->get_positions()[i]->get_weapons().size();j++){
		this->get_positions()[i]->get_weapons()[j].printinfo();
	}
	cout << "Shields:" << endl;
	for(int j=0;j<this->get_positions()[i]->get_armor().size();j++){
		this->get_positions()[i]->get_armor()[j].printinfo();
	}
	cout << "Potions:" << endl;
	for(int j=0;j<this->get_positions()[i]->get_potions().size();j++){
		this->get_positions()[i]->get_potions()[j].printinfo();
	}
	cout << "Spells:" << endl;
	for(int j=0;j<this->get_positions()[i]->get_spells().size();j++){
		this->get_positions()[i]->get_spells()[j]->printinfo();
	}
	string a;
	cout << "Which item/spell do you want to sell:" << endl;
	cin >> a;
	cout << endl;
	if(a=="fireball" || a=="inferno" || a=="eruption" || a=="chill" || a=="frostbite" || a=="avalanche" || a=="flash" || a=="lightning_strike" || a=="surging_soul"){
		for(int j=0;this->get_positions()[i]->get_spells().size();j++){
			if(this->get_positions()[i]->get_spells()[j]->get_name()==a){   //search and find item for sale
				this->get_positions()[i]->set_money(this->get_positions()[i]->get_spells()[j]->get_price()/2);    //sell it
				this->get_positions()[i]->get_spells().erase(this->get_positions()[i]->get_spells().begin()+j);   //delete it from inventory
				break;
			}
		}
	}
	else if(a=="straightsword" || a=="spear"  || a=="axe" || a=="greatsword" || a=="hammer" || a=="katana" || a=="widow_maker"){
		for(int j=0;this->get_positions()[i]->get_weapons().size();j++){
			if(this->get_positions()[i]->get_weapons()[j].get_name()==a){
				this->get_positions()[i]->set_money(this->get_positions()[i]->get_weapons()[j].get_price()/2);
				this->get_positions()[i]->get_weapons().erase(this->get_positions()[i]->get_weapons().begin()+j);
				break;
			}
		}
	}
	else if(a=="leather" || a=="wooden" || a=="steel" || a=="stone" || a=="nettle"){
		for(int j=0;this->get_positions()[i]->get_armor().size();j++){
			if(this->get_positions()[i]->get_armor()[j].get_name()==a){
				this->get_positions()[i]->set_money(this->get_positions()[i]->get_armor()[j].get_price()/2);
				this->get_positions()[i]->get_armor().erase(this->get_positions()[i]->get_armor().begin()+j);
				break;
			}
		}
	}
	else if(a=="health_potion" || a=="magic_potion" || a=="spinach" || a=="dope" || a=="cocaine" || a=="super_health_potion" || a=="super_magic_potion"){
		for(int j=0;this->get_positions()[i]->get_potions().size();j++){
			if(this->get_positions()[i]->get_potions()[j].get_name()==a){
				this->get_positions()[i]->set_money(this->get_positions()[i]->get_potions()[j].get_price()/2);
				this->get_positions()[i]->get_potions().erase(this->get_positions()[i]->get_potions().begin()+j);
				break;
			}
		}
	}
	else{
		return;
	}
}

commom::commom(){
}
commom::~commom(){
}
void commom::battle_chance(){
	if(rand()%2==1){             //the chance for a battle to happen
		Battle BTL;
		BTL.GamePlay(this->get_positions());
	}
}

nonAccessible::nonAccessible(){
}
nonAccessible::~nonAccessible(){
}


grid::grid(vector<Hero*>& herovector){
	for(int i=0;i<HEIGHT;i++){                //create randomly the squares of grid
		for(int j=0;j<LENGTH;j++){
			int k=rand()%4;
			if(i==0 && j==0){
				market *temp=new market();  //except the first square in which the heroes start
				mygrid[i][j]=temp;
				mygrid[i][j]->get_positions()=herovector;
			}
			else if(k==0 || k==1){
				commom *temp=new commom();
				mygrid[i][j]=temp;
			}
			else if(k==2){
				market *temp=new market();
				mygrid[i][j]=temp;
			}
			else{
				nonAccessible *temp=new nonAccessible();
				mygrid[i][j]=temp;
			}
		}
	}
}
grid::~grid(){
	for(int i=HEIGHT-1;i>=0;i--){
		for(int j=LENGTH-1;j>=0;j--){      //delete every square
			
			delete mygrid[i][j];
		}
	}
}

void grid::displayMap(){
	int a=0;    //a and b counts the squares
	int b=0;    // actually a=i
	for(int i=0;i<HEIGHT;i++){  //the height
		for(int j=0;j<3;j++){  
			if(j==0){  //make contour
				for(int k=0;k<=LENGTH*2;k++){   //contour
					if(k%2==0){
						cout<< "+";
					}
					else{
						cout << "--------";
					}
				}
			}
			else if(j==1){
				for(int k=0;k<=LENGTH*2;k++){//Square names + contour
					if(k%2==0){
						cout << "|";
					}
					else{
						cout << mygrid[a][b]->get_name(); 
						b++;
					}
				}
			}
			else{
				for(int k=0;k<=LENGTH*2;k++){//contour and hero names in the square
					if(k%2==0){
						cout << "|";
					}
					else{
	                    if(mygrid[a][b-LENGTH+k/2]->get_positions().size()==1){  //1 hero
	                    	cout << " H1     ";
						}
						else if(mygrid[a][b-LENGTH+k/2]->get_positions().size()==2){  //2 heroes
	                    	cout << " H1 H2  ";
						}
						else if(mygrid[a][b-LENGTH+k/2]->get_positions().size()==3){  //3 heroes
	                    	cout << " H1H2H3 ";
						}
						else
							cout << "        ";  //no heroes
					}
				}
			}
			cout << endl;
		}
	}
	for(int k=0;k<=LENGTH*2;k++){
		if(k%2==0){
			cout<< "+";
		}
		else{
			cout << "--------";
		}
	}
	cout << endl;
	a++;//////////////////////////////////////////////////////////////////////////////////////////////////////??????????
	b=0;
}

void grid::move(string d){
	if(d=="s"){            //go  up
		i++;
		if(i==HEIGHT){    //overload
			i=0;
		}
		if(mygrid[i][j]->get_name()=="noAccess"){  //check for nonAccessible squares
			cout << "noAccess" <<endl;
			if(i==0){
				i=HEIGHT-1;
			}
			else{
				i--;
			}
			return;
		}
		else{
			if(i!=0){
				mygrid[i][j]->get_positions()=mygrid[i-1][j]->get_positions();  //get them to next square
				mygrid[i-1][j]->get_positions().clear();                        //delete them from previous
			}
			else{
				mygrid[i][j]->get_positions()=mygrid[HEIGHT-1][j]->get_positions();
				mygrid[HEIGHT-1][j]->get_positions().clear();
			}
		}
	}
	else if(d=="w"){  //go down
		i--;
		if(i==-1){
			i=HEIGHT-1;
		}
		if(mygrid[i][j]->get_name()=="noAccess"){
			cout << "noAccess" <<endl;
			if(i==HEIGHT-1){
				i=0;
			}
			else{
				i++;
			}
			return;
		}
		else{
			if(i!=HEIGHT-1){
				mygrid[i][j]->get_positions()=mygrid[i+1][j]->get_positions();
				mygrid[i+1][j]->get_positions().clear();
			}
			else{
				mygrid[i][j]->get_positions()=mygrid[0][j]->get_positions();
				mygrid[0][j]->get_positions().clear();
			}
		}
	}
	else if(d=="a"){  //go left
		j--;
		if(j==-1){
			j=LENGTH-1;
		}
		if(mygrid[i][j]->get_name()=="noAccess"){
			cout << "noAccess" <<endl;
			if(j==LENGTH-1){
				j=0;
			}
			else{
				j++;
			}
			return;
		}
		else{
			if(j!=LENGTH-1){
				mygrid[i][j]->get_positions()=mygrid[i][j+1]->get_positions();
				mygrid[i][j+1]->get_positions().clear();
			}
			else{
				mygrid[i][j]->get_positions()=mygrid[i][0]->get_positions();
				mygrid[i][0]->get_positions().clear();
			}
		}	
	}
	else if(d=="d"){  //go right
		j++;
		if(j==LENGTH){
			j=0;
		}
		if(mygrid[i][j]->get_name()=="noAccess"){
			cout << "noAccess" <<endl;
			if(j==0){
				j=LENGTH-1;
			}
			else{
				j--;
			}
			return;
		}
		else{
			if(j!=0){
				mygrid[i][j]->get_positions()=mygrid[i][j-1]->get_positions();
				mygrid[i][j-1]->get_positions().clear();
			}
			else{
				mygrid[i][j]->get_positions()=mygrid[i][0]->get_positions();
				mygrid[i][0]->get_positions().clear();
			}
		}
	}
}
		
void grid::checkInventory(){   //check inventory of every hero
	for(int i=0;i<mygrid[this->get_i()][this->get_j()]->get_positions().size();i++){
		cout << "Legendary hero " << mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_name() <<" has:" << endl;
		cout << mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_money() << " coins" << endl;
		this->checkInventory(i);
	}
}

void grid::checkInventory(int i){  //print inventory of hero i
	cout << "Weapons:" << endl;
	for(int j=0;j<mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_weapons().size();j++){
		mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_weapons()[j].printinfo();
	}
	cout << "Shields:" << endl;
	for(int j=0;j<mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_armor().size();j++){
		mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_armor()[j].printinfo();
	}
	cout << "Potions:" << endl;
	for(int j=0;j<mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions().size();j++){
		mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].printinfo();
	}
	cout << "Spells:" << endl;
	for(int j=0;j<mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_spells().size();j++){
		mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_spells()[j]->printinfo();
	}
}

void grid::use(){  //use a potion
	string a, b;
	int i=0;
	if(mygrid[this->get_i()][this->get_j()]->get_positions().size()>1){  //who uses the potion?
		cout << "Who wants to use this potion?" << endl;
		cin >> b;
		cout << endl;
		for(int j=0;j<mygrid[this->get_i()][this->get_j()]->get_positions().size();j++){
			if(mygrid[this->get_i()][this->get_j()]->get_positions()[j]->get_name()==b){
				i=j;
				break;
			}
		}
	}
	cout << "Your potions:" << endl;  //print potions of hero
	for(int j=0;j<mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions().size();j++){
		mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].printinfo();
	}
	cout << "Which potion do you want to use?" << endl;
	cin>> a ;
	cout << endl;
	for(int j=0;mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions().size();j++){
			if(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].get_name()==a){   //check if he has the potion
				if(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].get_stat()=="healthPower"){  //use the potion
					mygrid[this->get_i()][this->get_j()]->get_positions()[i]->set_healthPower(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].get_plus());
				}
				else if(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].get_stat()=="magicPower"){
					mygrid[this->get_i()][this->get_j()]->get_positions()[i]->set_magicPower(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].get_plus());
				}
				else if(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].get_stat()=="strength"){
					mygrid[this->get_i()][this->get_j()]->get_positions()[i]->set_strength(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].get_plus());
				}
				else if(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].get_stat()=="agility"){
					mygrid[this->get_i()][this->get_j()]->get_positions()[i]->set_agility(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].get_plus());
				}
				else if(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].get_stat()=="dexterity"){
					mygrid[this->get_i()][this->get_j()]->get_positions()[i]->set_dexterity(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions()[j].get_plus());
				}  //and delete it after the use
				mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions().erase(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_potions().begin()+j);
			}
		}
}

bool grid::quitGame(){   
	cout << "Game Over" << endl;
	return false;
}

void grid::equip(){
	int i=0;
	string b;
	if(mygrid[this->get_i()][this->get_j()]->get_positions().size()>1){
		cout << "Who wants to equip weapons?" << endl;
		cin >> b;
		cout << endl;
		for(int j=0;j<mygrid[this->get_i()][this->get_j()]->get_positions().size();j++){
			if(mygrid[this->get_i()][this->get_j()]->get_positions()[j]->get_name()==b){
				i=j;
				break;
			}
		}
	}
	cout << "Do you want to equip a shield, " << mygrid[this->get_i()][this->get_j()]->get_positions()[j]->get_name() << "?" << endl;
	cin >> b;
	cout << endl;
	if(b=="yes" || b=="y"){
		cout << "Shields:" << endl;
		for(int j=0;j<mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_armor().size();j++){
			mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_armor()[j].printinfo();
		}
		cout << "Which one do you choose?" << endl;
		cin >> b;
		cout << endl;
		for(int j=0;mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_armor().size();j++){
			if(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_armor()[j].get_name()==b){  //right hand has shield
			if(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_leftHand()!=NULL && mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_leftHand()->get_doublehanded()){
					cout << "Can't equip because you hold double handed weapon" << endl;
			}
			else{
				mygrid[this->get_i()][this->get_j()]->get_positions()[i]->set_rightHand(&mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_armor()[j]);
				break;
			}
			}
		}
	}
	cout << "Do you want to equip a weapon, " << mygrid[this->get_i()][this->get_j()]->get_positions()[j]->get_name() << "?" << endl;
	cin >> b;
	cout << endl;
	if(b=="yes" || b=="y"){
		cout << "Weapons:" << endl;
		for(int j=0;j<mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_weapons().size();j++){  
			mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_weapons()[j].printinfo();
		}
		cout << "Which one do you choose?" << endl;
		cin >> b;
		cout << endl;
		for(int j=0;mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_weapons().size();j++){
			if(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_weapons()[j].get_name()==b){  //left hand weapon
				mygrid[this->get_i()][this->get_j()]->get_positions()[i]->set_leftHand(&mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_weapons()[j]);
				if(mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_rightHand()!=NULL && mygrid[this->get_i()][this->get_j()]->get_positions()[i]->get_leftHand()->get_doublehanded()){
						mygrid[this->get_i()][this->get_j()]->get_positions()[i]->set_rightHand(NULL);
					}
				break;
			}
		}
	}
}


