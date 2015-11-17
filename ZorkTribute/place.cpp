#include <iostream>
#include "place.h"
#include "items.h"

using namespace std;

//Initializes the starting point at the square, and the flags for conversation for those characters to 0 
Place::Place(){
	placeTypeNow = square;
	flagBlacksmith = 0;
	flagMerchant = 0;
	flagRiverLady = 0;
}

//Gives a brief description of the place you are in
void Place::Look(){
	switch (placeTypeNow){
	case square:
		cout<<"\nYou are at the town square, center of the town\n";
		break;
	case river:
		cout << "\nYou are at the river, the lady of the river looks upon you\n";
		break;
	case forge:
		cout << "\nYou are at the forge, a strong blacksmith stands before you\n";
		break;
	case market:
		cout << "\nYou can see a merchant among the crowd, he may have a shield\n";
		break;
	case gates:
		cout << "\nNow you have the gates of the city before you, make sure you are able to beat \nthe sieger before exiting the town\n";
		break;
	case hut:
		cout << "\nYou find a small hut isolated from the village, and you decide to go inside.\nYou can see a small chest in the middle of it\n";
		break;
	}
}

//Changes the place"room" when possible
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
		case 4:
			placeTypeNow = gates;
			Look();
			break;
		default:
			cout<<"\nYou can not go any further in that direction\n";
		}
		break;
	case river:
		switch (direction){
		case 2:
			placeTypeNow = market;
			Look();
			break;
		case 3:
			placeTypeNow = hut;
			Look();
			break;
		case 4:
			placeTypeNow = square;
			Look();
			break;
		default:
			cout<<"\nYou can not go any further in that direction\n";
		}
		break;
	case forge:
		switch (direction){
		case 1:
			placeTypeNow = hut;
			Look();
			break;
		case 2:
			placeTypeNow = square;
			Look();
			break;
		case 4:
			placeTypeNow = gates;
			Look();
			break;
		default:
			cout << "\nYou can not go any further in that direction\n";
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
		case 4:
			placeTypeNow = gates;
			Look();
			break;
		default:
			cout << "\nYou can not go any further in that direction\n";
		}
		break;
	case gates:
		switch (direction){
		case 1:
			placeTypeNow = square;
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
			cout << "\nYou can not go any further in that direction\n";
		}
		break;
	case hut:
		switch (direction){
		case 2:
			placeTypeNow = river;
			Look();
			break;
		case 4:
			placeTypeNow = forge;
			Look();
			break;
		default:
			cout << "\nYou can not go any further in that direction\n";
		}
		break;
	case outlands:
		cout << "\nYou can't go back into the town\n";
		break;
	default:
		cout << "\nYou can only go north west east or south\n";
	}
}

//If you are at the river, you can pray to the river's lady, she acts different if you have your weapons or not, and if you have your weapons blessed
void Place::Pray(Items* inventory){
	switch (placeTypeNow){
	case river:
		if (flagRiverLady == 0){
			if (inventory->itemOwned("sword") && inventory->itemOwned("shield")){
				cout << "\nGood job, now that you have your sword and shield,\nI will bless them so you can exit the town and fight the enemy\n";
				inventory->blessWeapons();
				flagRiverLady = 1;
			}
			else{
				cout << "\nIn order to beat the enemy, you will need a sword and a shield.\nBring them to me and I will bless them to ensure your victory\n";
			}
		}
		else{
			cout << "\nNow is your turn to show your value at battle\n";
		}
		break;
	default:
		cout << "\nYou can't pray right here\n";
	}
}

//Controls the conversation with the owners of sword and shield, as well as the answer to the riddles
void Place::Ask(const string who, Items* inventory){
	string answer;
	if (placeTypeNow == forge && !who.compare("blacksmith")){
		switch (flagBlacksmith){
		case 0:
			cout << "\nI can see you need a sword, it'll be yours if you can solve this riddle\nWhat's so delicate that saying its name breaks it?\n";
			getline(cin, answer);
			if (!answer.compare("silence")){
				cout << "\nYou're right! You can take the sword\n";
				flagBlacksmith = 1;
				inventory->makeItemObtainable("sword");
				return;
			}
			else{
				cout << "\nAye, as I expected you're not worth of my weaponry\nCome back if you think you know the answer\n";
				return;
			}
		case 1:
			cout << "\nI hope my sword serves you well\n";
			return;
		}
	}
	if (placeTypeNow == market && !who.compare("merchant")){
		switch (flagMerchant){
		case 0:
			cout << "\nSo you need a shield, right? \nThe price for it is 2 gold pieces.\n";
			cout << "But due to the special circumstances,if you can solve this riddle,you will have it for free.\n\n";
			cout << "Tuesday, Sam and Peter went to a restaurant to eat lunch. After eating lunch, \nthey paid the bill. But Sam and Peter did not pay the bill, so who did?\n";
			getline(cin, answer);
			if (!answer.compare("tuesday")){
				cout << "\nYou're right! You can take the shield\n";
				flagMerchant = 2;
				inventory->makeItemObtainable("shield");
				return;
			}
			else{
				cout << "\nYou had your chance and you misused it, now you will have to pay\n";
				flagMerchant = 1;
				return;
			}
		case 1:
			cout << "\nNow that you have failed, you will need to pay me\n";	
			return;
		case 2:
			cout << "\nI hope my shield serves you well\n";
			return;
		}
	}
	cout << "\nYou can't speak with him/her right now\n";
}

//Just calls the items class method
void Place::Take(const string what, Items* inventory){
	inventory->getItem(what, placeTypeNow);
}

//Just calls the items class method
void Place::Drop(const string what, Items* inventory){
	inventory->dropItem(what, placeTypeNow);
}

//You can only find a key at the town square, needed for the chest, and searching it, makes it obtainable
void Place::Search(const string what, Items* inventory){
	if (!what.compare("key") && placeTypeNow==square){
		inventory->makeItemObtainable(what);
		cout << "\nYou have found a key, now you can take it\n";
		return;
	}
	cout << "\nYou can find a " << what << " right here\n";
}

//If you've failed to correctly answer the merchant riddle you have top pay to make the shield obtainable
void Place::Pay(Items* inventory){
	switch (flagMerchant){
	case 1:
		if (inventory->itemOwned("gold") && placeTypeNow == market){
			inventory->makeItemObtainable("shield");
			cout << "\nNice to make deals with you, you can now take the shield\n";
			flagMerchant = 2;
		}
		else{
			cout << "\nYou can't pay in this moment\n";
		}
		break;
	default:
		cout << "\nYou can't pay in this moment\n";
	}
	
}

//This controls the end of the game, it's different if you have your weapons blessed or not or even if you exit without weapons, you can only exit the town from the gates
void Place::Exit(Items* inventory){
	if (placeTypeNow == gates){
		placeTypeNow = outlands;
		if (inventory->itemOwned("sword") && inventory->itemOwned("shield")){
			if (inventory->blessedWeapons()){
				cout << "\n\n\n\n\n\n\n\n\nYou face your enemy, a black dressed knight, that says\n-\"None shall pass!\" \nAfter a short battle, you sever his arm, but he claims\n-\"Tis but a scratch, I've'd worse\"\n";
				cout << "You cut off his other arm, but still doesn't concede and insists\n-\"It's just a flesh wound!\"\nIn response to the continued kicks and insults you chop his leg, but he doesn't admit his defeat";
				cout << " and says\n-\"Right, I'll do you for that, I'm INVINCIBLE!\"\nso with a sigh of resignation you sever his last limb and go back to the town \nwhile you hear him saying\n-\"Alright, let's call it a draw\"\n\n\nWrite quit to end the game\n";
			}
			else{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAfter a short battle he slays you, you should've blessed your weapons before \nfacing him\n\nWrite quit to end the game\n";
			}
		}
		else{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou're really brave to go out without weapons, but you've been slayed\n\nWrite quit to end the game\n";
		}
	}
	else{
		cout << "\nTo exit the town you need to be at the gates\n";
	}
}