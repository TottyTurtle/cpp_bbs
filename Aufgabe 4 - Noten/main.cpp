#include <iostream>

using namespace std;

#define round(var1) int(var1 * 10)/float(10);

int gesstudent; // Gesamtanzahl an Schüler


int getNoteInput(int value) {

noteInput:
    cout << "Geben Sie ein, wie oft es eine " << value << " gab: ";

    int student;
    cin >> student;

    if(cin.fail() || student < 0) { //Wenn Eingabe keine Zahl ist oder Eingabe im Minusbereich ist

        cin.clear(); //Error Flag löschen
        cin.ignore(128, '\n'); //Puffer löschen

        cout << "Ungueltige Eingabe!" << endl << endl;
        goto noteInput;
    }

    gesstudent += student;
    return student;
}

int main() {

    cout << "Notenprogramm v1.0" << endl;
    cout << "Programm zur Berechnung des Klassendurchschnitts einer Klassenarbeit." << endl << endl;

    float ges = 0.0; //Gesamtergebnis

    //Noten 1-6 durchgehen und abfragen
    for(int i=1;i<=6;i++) {
        ges += getNoteInput(i) * i;
    }

    ges = float(ges) / gesstudent; //Berechnung vom Durchschnitt

    ges = round(ges); //Runden auf 2 Nachkomastellen

    cout << endl << "Der Durchschnitt von " << gesstudent << " Schueler der Klassenabreit betraegt: " << ges << endl;
    cout << string(100, '_') << endl;


}

