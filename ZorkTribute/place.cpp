#include <iostream>
#include "place.h"

using namespace std;

Place::Place(const string place){
	if (!place.compare("Square"))
		placeTypeNow = square;
	if (!place.compare("River"))
		placeTypeNow = river;
}

void Place::Look(){
	switch (placeTypeNow){
	case square:
		cout<<"You are at the town square, center of the town\n";
		break;
	case river:
		cout << "You are at the river, the lady of the river looks upon you";
		break;
	}
}

void Place::Go(const int direction){
	cout << "Now I'm here";
	switch (placeTypeNow){
	case square:
		switch (direction){
		case 1:
			placeTypeNow = river;
			Look();
			break;
		default:
			cout<<"You can not go any further in that direction\n";
		}
		break;
	case river:
		switch (direction){
		case 4:
			placeTypeNow = square;
			Look();
			break;
		default:
			cout<<"You can not go any further in that direction\n";
		}
		break;
	}
}