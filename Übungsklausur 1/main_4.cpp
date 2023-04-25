#include <iostream>

using namespace std;

int main() {
    system("chcp 65001 > nul");

    cout << "Aufgabe 4 v1.0" << endl;
    cout << "Programm zum ausgeben von Namen in umgekehrter Reihenfolge" << endl << endl;


    string name1, name2, name3, name4;

    cout << "Geben Sie 4 Vornamen ein: ";
    cin >> name1;
    cin >> name2;
    cin >> name3;
    cin >> name4;

    cout << endl << "Eingabe: " << name4 << " " << name3 << " "  << name2 << " " << name1 << endl;
}
