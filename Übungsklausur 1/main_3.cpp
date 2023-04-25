#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    system("chcp 65001 > nul");

    cout << "Aufgabe 5 v1.0" << endl;
    cout << "Programme überprüft Zahl auf gerade oder ungerade" << endl << endl;

    cout << "Geben Sie eine Zahl ein: ";
    int num;
    cin >> num;

    num = num % 2;

    if(num == 0) {
        cout << "Diese Zahl ist gerade!" << endl;
    } else {
        cout << "Diese Zahl ist ungerade!" << endl;
    }

}
