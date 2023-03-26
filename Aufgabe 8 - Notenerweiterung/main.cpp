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

        cout << "Ungültige Eingabe!" << endl << endl;
        goto noteInput;
    }

    return student;
}

int main() {
    system("chcp 65001 > nul"); //UTF-8 support

    cout << "Notenprogramm v1.0" << endl;
    cout << "Programm zur Berechnung des Klassendurchschnitts einer Klassenarbeit." << endl << endl;

    float ges = 0.0; //Gesamtergebnis
    int failstudent = 0;

    //Noten 1-6 durchgehen und abfragen
    for(int i=1;i<=6;i++) {
        int notestudent = getNoteInput(i);
        gesstudent += notestudent;
        ges += notestudent * i;
        if(i>=5) {
            failstudent += notestudent;
        }
    }

    ges = float(ges) / gesstudent; //Berechnung vom Durchschnitt

    ges = round(ges); //Runden auf 2 Nachkomastellen

    cout << endl << "Der Durchschnitt von " << gesstudent << " Schüler der Klassenabreit beträgt: " << ges;
    float fail = ((100 / float(gesstudent)) * failstudent);

    // cout << gesstudent << " - " << failstudent << " < " <<fail;
    if(fail > 30) {
        cout << " (Die Klassenarbeit muss wiederholt werden!)" << endl;
    }
    cout << endl << string(100, '_') << endl;


}

