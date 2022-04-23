#include <iostream>
#include <queue>
#include "List.h"
using namespace std;

int main() {
	List <int>* l = new List <int> ();
	l->AddToTail(3);
	l->AddToHead(2);
	l->AddToHead(1);
	l->AddToTail(4);
	l->AddToTail(5);
	cout << setw(4) << "List: ";
	l->Show();
	cout << endl;
	cout << setw(4) <<"InsertByPos(4, 3):  ";
	l->InsertByPos(4, 3);
	l->Show();
	cout << endl;
	l->DelByPos(2);
	cout << setw(4) <<"DelByPos(2):    ";
	l->Show();
	cout << endl;
	int k = l->SearchEL(3);
	cout << setw(4) <<"SearchEL (3)  "<<"  qt-y el: " << k << endl;
	cout << endl;
	l->SearchAndRepl(3, 7);
	cout << setw(4) <<"SearchAndRepl(3, 7):   ";
	l->Show();
	l->Reverse();
	cout << endl;
	cout << setw(4) << "Reverse():    " ;
	l->Show();
	return 0;
}