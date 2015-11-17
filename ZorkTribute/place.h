#ifndef _PLACE_
#define _PLACE_

#include <string>

using namespace std;

class Items;

//As the actions performed depend on the place we are now, this one has most of the methods
class Place{
	enum placeType{ square, river,forge,market, gates, hut,outlands};
private:
	string presentation;
	placeType placeTypeNow;
	int flagBlacksmith;
	int flagMerchant;
	int flagRiverLady;
public:
	Place();
	void Look();
	void Go(const int);
	void Pray(Items*);
	void Ask(const string, Items*);
	void Take(const string, Items*);
	void Drop(const string, Items*);
	void Search(const string, Items*);
	void Pay(Items*);
	void Exit(Items*);
};
#endif //_PLACE_