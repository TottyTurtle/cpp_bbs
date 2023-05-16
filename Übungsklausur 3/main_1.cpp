#include <iostream>
using namespace std;

string inputString(string request) {
    cout << request;
    string value;
    cin >> value;
    return value;
}
char inputChar(string request) {
    cout << request;
    char value;
    cin >> value;
    return value;
}
double inputDouble(string request) {
    cout << request;
    double value;
    cin >> value;
    return value;
}

int main() {
    system("chcp 65001 > nul");//Kodierung bitte umstellen: Oben links -> "Edit" -> "File Encoding" -> "UTF-8"

    cout << "Aufgabe 7 v1.0" << endl;
    cout << "Rabattprogramm" << endl << endl;

    string anrede = "",
           nachname = inputString("Wie ist ihr Nachname? ");

    switch(inputChar("Sind Sie männlich oder weiblich?\nBitte geben Sie m oder w ein!\n")) {
        case 'm':
            anrede = "Herr";
            break;
        case 'w':
            anrede = "Frau";
            break;
    }

    cout << "Willkommen " << anrede << " " << nachname << endl;

    double preis = inputDouble("Geben Sie einen Preis ein: ");
    preis = preis - (preis / 100 * 20);

    switch(inputChar("Soll die Ware geliefert werden? j / n\n")) {
        case 'j':
            preis += 6.90;
            break;
    }

    cout << anrede << " " << nachname << ", bitte zahlen Sie den Endbetrag von: " << preis << " Euro" << endl << endl;
    system("Pause");
}
