#include <iostream>
#include "Village.h"
#include "place.h"
#include "player.h"
#include "items.h"

using namespace std;

Village::Village(){
	placeNow = new Place();
	hero = new Player();
	inventory = new Items();
}

void Village::receiveOrder(string order){
	if (!order.compare(0, 2, "go")){
		if (order.length() == 2){
			cout << "You should decide where to go";
		}
		else if (!order.compare(3, 5, "north")){
			placeNow->Go(1);
		}
		else if (!order.compare(3, 4, "west")){
			placeNow->Go(2);
		}
		else if (!order.compare(3, 4, "east")){
			placeNow->Go(3);
		}
		else if (!order.compare(3, 5, "south")){
			placeNow->Go(4);
		}
	}
	else if (!order.compare("look")){
		placeNow->Look();
	}
	else if (!order.compare("pray")){
		placeNow->Pray(inventory);
	}
	else if (!order.compare(0, 3, "ask")){
		if (order.length() == 3){
			cout << "ask, okay, but ask who?";
		}
		else{
			placeNow->Ask(order.substr(4), inventory);
		}
	}
	else if (!order.compare(0, 4, "take")){
		if (order.length() == 4){
			cout << "take, okay, but take what?";
		}
		else{
			placeNow->Take(order.substr(5), inventory);
		}
	}
	else{
		cout << "Unkonwn order\n";
	}
}
