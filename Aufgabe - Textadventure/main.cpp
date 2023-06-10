#include <iostream>
#include <unistd.h>

using namespace std;


int main() {
    cout << "test" << endl;

	cout << "test:  5% x..................." << "\r";
	cout.flush ();
	sleep (1);
	cout << "test: 10% xx.................." << "\r";
	cout.flush ();
	sleep (1);
	cout << "test: 20% xxxx................" << "\r";
	cout.flush ();
	sleep (1);
	cout << "test: 80% xxxxxxxxxxxxxxxx...." << "\r";
	cout.flush ();
	sleep (1);
	cout << endl;

}
