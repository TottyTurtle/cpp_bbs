
#include <iostream>
#include <stdlib.h>
#include <stdarg.h>
#include <string>
#include "Rechner.h"
using namespace std;


int main() {
    while(true) {

invalid:
        cout << "Gib eine Zahl ein:" << endl;

        int number;
        cin >> number;

        if(cin.fail()) {
            cin.clear();
            cin.ignore();

            cerr << "Keine Zahl angegeben!" << endl;

            goto invalid;
        }

        cout << "Zahl: " << number << " angegeben" << endl;

        cout << string(40, '-') << endl;

    }
}

    /*
    #define startWith(var1, var2) var2.rfind(var1, 0) == 0

    string text = "TestTest";

    if(startWith("Test", text)) {
        cout << "ok" << endl;
    }


    int num;
    Rechner r;
    cout << r.plus(3, 2, 3, 4) << endl;

    cout << r.minus(5, 20, 4, 2, 1, 1);
*/
    /*while(true) {

        cout << "Gib eine Zahl an:" << endl;
        cin >> num;

        if(cin.fail()) {
            cin.clear();
            cin.ignore();
            cerr << "Keine Zahl angegeben" << endl;
            continue;
        }

        cout << num << endl;
    }*/



