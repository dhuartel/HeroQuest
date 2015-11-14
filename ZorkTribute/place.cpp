#include <iostream>
#include "place.h"
#include "items.h"

using namespace std;

Place::Place(){
	placeTypeNow = square;
}

void Place::Look(){
	switch (placeTypeNow){
	case square:
		cout<<"You are at the town square, center of the town\n";
		break;
	case river:
		cout << "You are at the river, the lady of the river looks upon you\n";
		break;
	case forge:
		cout << "You are at the forge, a strong blacksmith stands before you\n";
		break;
	case market:
		cout << "You can see a merchant among the crowd, he may have a shield\n";
		break;
	}
}

void Place::Go(const int direction){
	switch (placeTypeNow){
	case square:
		switch (direction){
		case 1:
			placeTypeNow = river;
			Look();
			break;
		case 2:
			placeTypeNow = market;
			Look();
			break;
		case 3:
			placeTypeNow = forge;
			Look();
			break;
		default:
			cout<<"You can not go any further in that direction\n";
		}
		break;
	case river:
		switch (direction){
		case 2:
			placeTypeNow = market;
			Look();
			break;
		case 3:
			placeTypeNow = forge;
			Look();
			break;
		case 4:
			placeTypeNow = square;
			Look();
			break;
		default:
			cout<<"You can not go any further in that direction\n";
		}
		break;
	case forge:
		switch (direction){
		case 1:
			placeTypeNow = river;
			Look();
			break;
		case 2:
			placeTypeNow = square;
			Look();
			break;
		default:
			cout << "You can not go any further in that direction\n";
		}
		break;
	case market:
		switch (direction){
		case 1:
			placeTypeNow = river;
			Look();
			break;
		case 3:
			placeTypeNow = square;
			Look();
			break;
		default:
			cout << "You can not go any further in that direction\n";
		}
		break;
	}

}

void Place::Pray(Items* inventory){
	switch (placeTypeNow){
	case river:
		if (inventory->checkSwordAndShield()){
			cout << "Good job, now that you have your sword and shield\nI will bless them so you can exit the town and fight the enemy\n";
			inventory->blessWeapons();
		}
		else{
			cout << "In order to beat the enemy, you will need a sword and a shield.\nBring them to me and I will bless them to ensure your victory\n";
		}
		break;
	default:
		cout << "You can't pray right here\n";
	}
}

void Place::Ask(string who, Items* inventory){
	if (placeTypeNow == forge && !who.compare("blacksmith")){
		cout << "I can see you need a sword, it'll be yours if you can solve this riddle\nWhat's so delicate that saying its name breaks it?\n";
		string answer;
		getline(cin, answer);
		if (!answer.compare("silence")){
			cout << "You're right! You can take the sword\n";
			inventory->makeSwordObtainable();
		}
		else{
			cout << "Aye, as I expected you're not worth of my weaponry\n Come back if you think you know the answer\n";
		}
	}
	if (placeTypeNow == market && !who.compare("merchant")){
		cout << "So you need a shield, right? \nThe price for it is 2 gold pieces.\n";
		cout << "But due to the special circumstances,\nif you can solve this riddle, you will have it for free.\n";
		cout << "According to the Monty Pythonesque application of the principles of logic and\netymology,\n";
		cout << "Why are firetrucks red?\nYou have just one chance(remember, no capital letters, no punctuation signs and only a white space between word and word)\nHint: wolframalpha\n";
		string answer;
		getline(cin, answer);
		if (!answer.compare("a")){//because they have eight wheels and four people on them and four plus eight is twelve and there are twelve inches in a foot and one foot is a ruler and queen elizabeth was a ruler and queen elizabeth was also a ship and the ship sailed the seas and in the seas are fish and fish have fins and the finns fought the russians and the russians are red and fire trucks are always russian around
			cout << "You're right! You can take the shield\n";
			inventory->makeShieldObtainable();
		}
		else{
			cout << "Aye, as I expected you're not worth of my weaponry\n Come back if you think you know the answer\n";
			cout << answer<<"\n";
		}
	}
	else{
		cout << "You can't speak with him/her right now\n";
	}
}

void Place::Take(string what, Items* inventory){
	if (placeTypeNow == forge && !what.compare("sword")){
		inventory->getSword();
	}
	else if (placeTypeNow == market && !what.compare("shield")){
		inventory->getShield();
	}
	else{
		cout << "You can't take that right now\n";
	}
}