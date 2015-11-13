#include <string>
using namespace std;

class Place;

class Village{
public:
	Village();
	void receiveOrder(string order);
private:
	Place* placeNow;
};