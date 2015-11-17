#include <iostream>
#include "Village.h"
#include "place.h"
#include "items.h"

using namespace std;

Village::Village(){
	placeNow = new Place();
	inventory = new Items();
}

//This method reads the order received and calss the correspondent method
void Village::receiveOrder(const string order){
	//If you write go and a correct direction it calls the method to move if you can
	if (!order.compare(0, 2, "go")){
		if (order.length() == 2){
			cout << "\nYou should decide where to go";
		}
		else if (!order.compare(3, order.length()-3, "north")){
			placeNow->Go(1);
		}
		else if (!order.compare(3, order.length() - 3, "west")){
			placeNow->Go(2);
		}
		else if (!order.compare(3, order.length() - 3, "east")){
			placeNow->Go(3);
		}
		else if (!order.compare(3, order.length() - 3, "south")){
			placeNow->Go(4);
		}
		else{
			cout << "\nI don't understand where do you want to go\n";
		}
	}
	//It calls the method that gives a brief description of the place you are at
	else if (!order.compare("look")){
		placeNow->Look();
	}
	//It calls the method that connects you to the river's lady if you are at the river
	else if (!order.compare("pray")){
		placeNow->Pray(inventory);
	}
	//If you ask someone it calls the method that starts the conversation if able to
	else if (!order.compare(0, 3, "ask")){
		if (order.length() == 3){
			cout << "\nask, okay, but ask who?\n";
		}
		else{
			placeNow->Ask(order.substr(4), inventory);
		}
	}
	//If you take something it calls the method that adds it to the inventory if able to
	else if (!order.compare(0, 4, "take")){
		if (order.length() == 4){
			cout << "\ntake, okay, but take what?\n";
		}
		else{
			placeNow->Take(order.substr(5), inventory);
		}
	}
	//If you drop something it calls the method that takes it from the inventory if able to
	else if (!order.compare(0, 4, "drop")){
		if (order.length() == 4){
			cout << "\ndrop, okay, but drop what?\n";
		}
		else{
			placeNow->Drop(order.substr(5), inventory);
		}
	}
	//If you try to open the chest it calls the method to open it if possible
	else if (!order.compare(0, 4, "open")){
		if (order.length() == 4){
			cout << "\nopen, okay, but open what?\n";
		}
		else{
			if (order.compare(5, order.length() - 5, "chest")){
				cout << "\nYou can't open that\n";
			}
			else{
				inventory->openChest();
			}
		}
	}
	//If you search something it calls the method that makes it obtainable if able to
	else if (!order.compare(0, 6, "search")){
		if (order.length() == 6){
			cout << "\nsearch, okay, but search what?\n";
		}
		else{
			placeNow->Search(order.substr(7), inventory);
		}
	}
	//It calls the method that prints all the owned items
	else if (!order.compare("inventory")){
		inventory->checkInventory();
	}
	//It calls the method that pays if possible
	else if (!order.compare("pay")){
		placeNow->Pay(inventory);
	}
	//It calls the method that exits the town if possible
	else if (!order.compare("exit")){
		placeNow->Exit(inventory);
	}
	//Calls the info method
	else if (!order.compare("info")){
		Info();
	}
	//Calls the help method
	else if (!order.compare("help")){
		Help();
	}
	//If the written order doesn't correspond with any real order
	else{
		cout << "\nUnkonwn order\n";
	}
}


//Gives info of the game
void Village::Info(){
	cout << "\nHello, this will be the adventure of your life. \nA powerfull enemy is sieging our town, but you can obtain River Lady's favour \nand slay the invader.\n";
}


//Shows a list of the commands you can use
void Village::Help(){
	cout << "\nYou can use the following commands:\n";
	cout << "-go (north,east,west,south)\n";
	cout << "-look\n";
	cout << "-take \"something\"\n";
	cout << "-drop \"something\"\n";
	cout << "-open \"something\"\n";
	cout << "-search \"something\"\n";
	cout << "-ask \"someone\"\n";
	cout << "-pray\n";
	cout << "-pay\n";
	cout << "-exit\n";
	cout << "-inventory\n";
	cout << "-info\n";
	cout << "-help\n";
	cout << "-quit (to exit the game)\n";
}
