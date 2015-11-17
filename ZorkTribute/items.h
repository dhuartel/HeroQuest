#ifndef _ITEMS_
#define _ITEMS_

#include<string>
#include <list>

using namespace std;

typedef struct{ 
	string name;//name of the item
	int placement;//"room" they are in
	bool owned;//has the player taken it
	bool obtainable;//can the player take it
	bool blessed;//just for weapons
} item;

class Items{
private:	
	list<item> setOfItems;
	void fillItemList();
	bool itemObtainable(const string);
public:
	Items();
	void getItem(const string, const int);
	void dropItem(const string, const int);
	void makeItemObtainable(const string);
	void blessWeapons();
	void openChest();
	bool blessedWeapons();
	void checkInventory();
	bool itemOwned(const string);
};
#endif //_ITEMS_