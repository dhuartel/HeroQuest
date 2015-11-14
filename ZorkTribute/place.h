#include <string>

using namespace std;

class Items;

class Place{
	enum placeType{ square, river,forge,market};
private:
	string presentation;
	placeType placeTypeNow;
public:
	Place();
	void Look();
	void Go(const int);
	void Pray(Items*);
	void Ask(string , Items* );
	void Take(string , Items* );
};