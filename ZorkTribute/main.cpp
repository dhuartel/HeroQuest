#include <iostream>
#include <string>
#include <Windows.h>
#include "village.h"
using namespace std;

int main()
{
	cout << "Hello, this will be the adventure of your life. \nA powerfull enemy is sieging our town,\nbut you can obtain River Lady's favour and slay the invader.\n";
	string input;
	Village tintagel;
	while (1){
		getline(cin,input);
		if (!input.compare("exit")){
			cout << "Hope you enjoyed the game!";
			Sleep(500);
			exit(0);
		}
		tintagel.receiveOrder(input);
	}
}
