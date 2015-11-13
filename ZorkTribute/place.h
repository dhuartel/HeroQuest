#include <string>

using namespace std;

class Place{
	enum placeType{ square, river };
private:
	string presentation;
	placeType placeTypeNow;
public:
	Place(const string type);
	void Look();
	void Go(const int direction);
};