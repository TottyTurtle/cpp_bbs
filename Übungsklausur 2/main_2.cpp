#include <iostream>
#include <time.h>
using namespace std;



int main() {
    system("chcp 65001 > nul");
    srand((unsigned) time(NULL));

    cout << "Aufgabe 2 v1.0" << endl;
    cout << "Programm Passwort geneator" << endl << endl;

    string zeichenkette, passwort;
    cout << "Geben Sie Buchstaben und Zahlen ein: ";
    cin >> zeichenkette;

    int m, zeichen_size = zeichenkette.size()-1;
    char zeichen;


    for(int i=0;i<zeichen_size;i++) {
        m = rand() % (zeichenkette.size() - 1);
        zeichen = zeichenkette[m];
        passwort += zeichen;
        zeichenkette.erase(m,1);
    }
    passwort = passwort + zeichenkette;
    cout << endl << "Dein Passwort lautet: " << passwort << endl;
}
