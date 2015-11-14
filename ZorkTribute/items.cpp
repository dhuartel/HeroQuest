#include "items.h";
#include <iostream>

using namespace std;

Items::Items(){
	fillItemList();
}

void Items::fillItemList(){
	item aux;
	aux.name = "sword";
	aux.placement = 3;
	aux.obtainable = false;
	aux.owned = false;
	aux.blessed = false;
	setOfItems.insert(setOfItems.end(), aux);
	aux.name = "shield";
	aux.placement = 2;
	setOfItems.insert(setOfItems.end(), aux);
}

bool Items::checkSwordAndShield(){
	list<item>::iterator it = setOfItems.begin();
	bool aux=it->owned;
	++it;
	aux &= it->owned;
	return aux;
}

void  Items::makeSwordObtainable(){
	setOfItems.begin()->obtainable = true;
}

void  Items::makeShieldObtainable(){
	list<item>::iterator it = setOfItems.begin();
	++it;
	it->obtainable = true;
}

void  Items::getSword(){
	if (setOfItems.begin()->obtainable){
		setOfItems.begin()->owned = true;
		cout << "Now you have the sword\n";
	}
	else{
		cout << "You can't take the sword without the blacksmith agreement, that wouldn't be\nclever\n";
	}
}

void  Items::getShield(){
	list<item>::iterator it = setOfItems.begin();
	++it;
	if (it->obtainable){
		it->owned = true;
		cout << "Now you have the shield\n";
	}
	else{
		cout << "You can't take the shield without the merchant agreement, that's theft\n";
	}
}

void Items::blessWeapons(){
	list<item>::iterator it = setOfItems.begin();
	it->blessed = true;
	++it;
	it->blessed = true;
}