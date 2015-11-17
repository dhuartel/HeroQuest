#ifndef _VILLAGE_
#define _VILLAGE_

#include <string>
using namespace std;

class Place;
class Player;
class Items;

//Class that controls the whole game, has the inventory and calls the different methods according to the order received
class Village{
public:
	Village();
	void receiveOrder(const string order);
private:
	Place* placeNow;
	Player* hero;
	Items* inventory;
	//These are private since there is no need of calling them from other classes
	void Info();
	void Help();
};
#endif //_VILLAGE_