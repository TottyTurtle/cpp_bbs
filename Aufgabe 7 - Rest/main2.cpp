#include <iostream>
using namespace std;

int getInput(string text) {
newinput:
    cout << text;
    int value;
    cin >> value;

    if(cin.fail()) {
        cin.clear();
        cin.ignore(128, '\n');

        cout << "Ungültige Eingabe!" << endl;
        goto newinput;
    }
    return value;
}

void rechner() {
    int value = getInput("Geben Sie eine Zahl ein: ");
    int divisor = getInput("Geben Sie den Divisor ein: ");

    int modulo = value % divisor;

    cout << endl;
    cout << "Aufgabe: " << value << " / " << divisor << endl;

    cout << "Ergebnis: " << (value / divisor);
    if(modulo > 0) {
      cout << " Rest: " << modulo;
    }
}

int main() {
    system("chcp 65001 > nul"); //UTF-8 support

    cout << "Restchecker v1.0" << endl;
    cout << "Programm dass prüft, ob die Division ohne Rest möglich ist" << endl << endl;

    char ask;
    while(ask != 'n') { // Unendliche Wiederholungen
        rechner();
        cout << endl << endl << string(60, '_') << endl << endl;
        cout << "Wollen Sie eine weitere Berechnung durchführen? [J]a [N]ein";

        cin >> ask;
        cout << endl << endl;
    }
}
