#include <iostream>
#include <string>
#include <Windows.h>
#include "village.h"
using namespace std;

int main()
{	
	Village tintagel;
	tintagel.receiveOrder("info");	
	string input="look";
	while (1){
		if (!input.compare("quit")){
			cout << "\nHope you enjoyed the game!";
			Sleep(1500);
			exit(0);
		}
		tintagel.receiveOrder(input);
		getline(cin, input);
	}
}

