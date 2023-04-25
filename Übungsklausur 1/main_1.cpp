#include <iostream>

#define pi 3.14159

using namespace std;

int main() {
    system("chcp 65001 > nul");

    cout << "Aufgabe 1 v1.0" << endl;
    cout << "Programm zur Berechnung von Umfang und Fläche eines Kreises" << endl << endl;

    cout << "Geben Sie den Radius an: ";
    int radius;
    cin >> radius;

    float durchmesser = 2 * pi * radius;
    float flaeche = pi * radius * radius;

    cout << endl << "Der Durchmesser beträgt: " << durchmesser << endl;
    cout << "Die Fläche beträgt: " << flaeche << endl;
}
