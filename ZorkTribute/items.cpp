#include "items.h";
#include <iostream>

using namespace std;

Items::Items(){
	fillItemList();
}

//Insert all the items into the list
void Items::fillItemList(){
	item aux;//Creating just one auxiliar item to fill the lis serves well, just need to change the fields needed
	aux.name = "sword";
	aux.placement = 2;
	aux.obtainable = false;
	aux.owned = false;
	aux.blessed = false;
	setOfItems.insert(setOfItems.end(), aux);

	aux.name = "shield";
	aux.placement = 3;
	setOfItems.insert(setOfItems.end(), aux);

	aux.name = "key";
	aux.placement = 0;
	setOfItems.insert(setOfItems.end(), aux);

	aux.name = "gold";
	aux.placement = 5;
	setOfItems.insert(setOfItems.end(), aux);

	aux.name = "chest";
	aux.obtainable = true;
	aux.placement = 5;
	setOfItems.insert(setOfItems.end(), aux);
}

//Take an item
void Items::getItem(const string name, const int place){
	list<item>::iterator it;
	for (it = setOfItems.begin(); it != setOfItems.end(); ++it){
		//Searches for an item with the given name
		if (!name.compare(it->name)){
			//Checks if you own the item
			if (itemOwned(name)){
				cout << "\nYou already've it\n";
				return;
			}
			else{
				//Checks if the place you are now is the place where the item is or if it's gold since it is inside the chest that you carry
				if (place == it->placement || !name.compare("gold")){
					//Checks if you can take the item
					if (itemObtainable(name)){
						it->owned = true;
						cout << "\nYou have taken the " << name << "\n";
						return;
					}
					else{
						cout << "\nYou can't take it right now\n";
						return;
					}
				}
			}
		}
	}
	//Since I use return inside the searching loop, it doesn't access this part of code always
	cout << "\nYou can't see any " << name << " around\n";
}

//Drop an item
void Items::dropItem(const string name, const int place){
	list<item>::iterator it;
	for (it = setOfItems.begin(); it != setOfItems.end(); ++it){
		//Searches for an item with the given name
		if (!name.compare(it->name)){
			//Checks if you own the item
			if (itemOwned(name)){
				//Checks if you are trying to drop the gold
				if (!name.compare("gold")){
					cout << "\nYou fool, why in hell would you want to drop gold\n";
					return;
				}
				else{
					cout << "\nYou've dropped the " << name << "\n";
					it->placement = place;
					it->owned = false;
					if (!name.compare("chest")){
						//This "closes" the chest
						for (it = setOfItems.begin(); it != setOfItems.end(); ++it){
							if (!it->name.compare("gold")){
								it->obtainable = false;
							}
						}
					}
					return;
				}
			}
		}
	}
	//Since I use return inside the searching loop, it doesn't access this part of code always
	cout << "\nYou don't own it\n";
}

//Returns true if you own the item, false if you don't have it yet
bool Items::itemOwned(const string name){
	list<item>::iterator it = setOfItems.begin();
	for (it = setOfItems.begin(); it != setOfItems.end(); ++it){
		if (!it->name.compare(name)){
			return it->owned;
		}
	}
}

//Allows you to take the item from now on
void Items::makeItemObtainable(const string name){
	list<item>::iterator it;
	for (it = setOfItems.begin(); it != setOfItems.end(); ++it){
		if (!name.compare(it->name)){
			it->obtainable = true;
		}
	}
}

//Blesses the sword and shiled, it doesn't need to check if they are owned since it is done before the call to the function
void Items::blessWeapons(){
	list<item>::iterator it = setOfItems.begin();
	for (it = setOfItems.begin(); it != setOfItems.end(); ++it){
		if (!it->name.compare("sword") || !it->name.compare("shield")){
			it->blessed = true;
		}
	}
}

//Opens the chest if you own both the chest and the key, making the gold obtainable
void Items::openChest(){
	list<item>::iterator it;
	//The gold is only obtainable if you have the chest open, so it serves well to check
	if (itemObtainable("gold")){
		cout << "\nThe chest is already open\n";
		return;
	}
	else{
		for (it = setOfItems.begin(); it != setOfItems.end(); ++it){
			if (!it->name.compare("chest") && it->owned == true){
				for (it = setOfItems.begin(); it != setOfItems.end(); ++it){
					if (!it->name.compare("key") && it->owned == true){
						//Shows a different message if you have already taken the gold or not 
						if (itemOwned("gold")){
							cout << "\nYou've opened the chest, but it's been emptied before\n";
						}
						else{
							cout << "\nThe chest is open, there is gold inside\n";
						}
						makeItemObtainable("gold");
						return;
					}
				}
				cout << "\nThe chest can't be opened without a key\n";
				return;
			}
		}
	}
	cout << "\nYou don't have a chest to be opened in your inventory\n";
	return;
}

//Returns a list of all the owned items
void Items::checkInventory(){
	cout << "\n";
	list<item>::iterator it;
	for (it = setOfItems.begin(); it != setOfItems.end(); ++it){
		if (it->owned){
			cout << it->name << "\n";
		}
	}
}

//Returns true if sword and shield are blessed, false if not
bool Items::blessedWeapons(){
	list<item>::iterator it = setOfItems.begin();
	bool aux = true;
	for (it = setOfItems.begin(); it != setOfItems.end(); ++it){
		if (!it->name.compare("sword") || !it->name.compare("shield")){
			aux &= it->blessed;
		}
	}
	return aux;
}

//Returns true if you can obtain the item, false if you can't
bool Items::itemObtainable(const string name){
	list<item>::iterator it = setOfItems.begin();
	for (it = setOfItems.begin(); it != setOfItems.end(); ++it){
		if (!it->name.compare(name)){
			return it->obtainable;
		}
	}
}