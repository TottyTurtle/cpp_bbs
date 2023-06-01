#include <iostream>
#include <windows.h>
#include <thread>

using namespace std;

int option, number, gesamt = 15;

int main() {
    system("chcp 65001 > nul"); //UTF-8 support
    srand (time(NULL));

    cout << "Hölzchenspiel v1.0" << endl;
    cout << "Spiel um das letzte Hölzchen" << endl << endl;

    cout << "Wähle eine Schwierigkeit:" << endl;
    cout << "1. Leicht 2. Schwer" << endl;

    cin >> option;

    if(option == 2) {
        cout  << endl << "Schwierigkeit Schwer ausgewählt." << endl << endl;
    } else {
        cout  << endl << "Schwierigkeit Leicht ausgewählt." << endl << endl;
    }

    cout << string(30, '_') << endl;
    cout << "Das Spiel beginnt!" << endl << endl;

    while(gesamt > 0) {
        cout << "Es sind noch " << gesamt << " Hölzchen im Spiel." << endl<< endl;
        //Spieler
        cout << "Wie viele willst du nehmen? ";
        cin >> number;
        if(number > 3) {
            number = 3;
        } else if(number < 1) {
            number = 1;
        }
        cout << "Du hast "  << number << " Hölzchen genommen." << endl;
        gesamt -= number;

        if(gesamt < 1) {
            cout << endl << string(30, '$') << endl;
            cout << "Der Computer hat Gewonnen!" << endl;
            cout << string(30, '$') << endl << endl;
            continue;
        }

        cout << "Es sind noch " << gesamt << " Hölzchen im Spiel." << endl<< endl;

        //Computer
        if(option == 1) {
            number = rand() % 3 + 1;
        } else {
            if(gesamt > 13) {
                number = gesamt - 13;

            } else if(gesamt > 9) {
                number = gesamt - 9;

            } else if(gesamt > 5) {
                number = gesamt - 5;

            } else {
                number = gesamt - 1;

            }
            if(number > 3 || number < 1) {
                number = rand() % 3 + 1;
            }
        }

        cout << "Der Computer hat " << number << " Hölzchen genommen." << endl;
        gesamt -= number;
        if(gesamt < 1) {
            cout << endl << string(30, '$') << endl;
            cout << "Du hast Gewonnen!" << endl;
            cout << string(30, '$') << endl << endl;
            continue;
        }
    }
    system("pause");

}
