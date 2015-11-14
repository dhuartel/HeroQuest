#include<string>
#include <list>

using namespace std;

typedef struct{ 
	string name;
	int placement;
	bool owned;
	bool obtainable;
	bool blessed;
} item;

class Items{
private:	
	list<item> setOfItems;
	void fillItemList();
public:
	Items();
	void getSword();
	void getShield();
	void makeSwordObtainable();
	void makeShieldObtainable();
	void blessWeapons();
	bool checkSwordAndShield();
};