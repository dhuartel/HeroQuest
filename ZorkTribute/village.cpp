#include <iostream>
#include "Village.h"
#include "place.h"

using namespace std;

Village::Village(){
	placeNow = new Place("Square");
}

void Village::receiveOrder(string order){
	if (!order.compare(0, 2, "go")){
		if (!order.compare(3, 5, "north")){
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
	if (!order.compare("look")){
		placeNow->Look();
	}

}
