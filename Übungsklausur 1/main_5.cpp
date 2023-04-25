#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    system("chcp 65001 > nul");

    cout << "Aufgabe 5 v1.0" << endl;
    cout << "Programme mit Zufallsfunktion (a – c)!" << endl << endl;

    int x;

    srand((unsigned) time(NULL));
    x=rand();


    int dice = (x % 6) + 1,
        number = x % 50,
        win = x % 2;

    number = number % 2 == 0 ? number : number + 51;

    cout << "Aufgabe a) " << "Würfel: " << dice << endl;
    cout << "Aufgabe b) " << "Gerade Zahl 0-100: " << number << endl;
    cout << "Aufgabe c) " << "Würfel: " << (win == 0 ? "gewonnen" : "verloren") << endl;

}
