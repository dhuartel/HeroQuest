#include <string>
using namespace std;

class Place;
class Player;
class Items;

class Village{
public:
	Village();
	void receiveOrder(string order);
private:
	Place* placeNow;
	Player* hero;
	Items* inventory;
};