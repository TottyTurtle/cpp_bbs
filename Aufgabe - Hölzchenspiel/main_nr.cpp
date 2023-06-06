#include <iostream>
#include <time.h>

using namespace std;

int schwirigkeit,
    hoelzchen;

int main() {
    system("chcp 65001 > nul"); //UTF-8 support
    srand (time(NULL));

    cout << "Hölzchenspiel v1.0" << endl;
    cout << "Letzte Hölzchen von 15 verliert" << endl << endl;

    cout << "Wähle zwischen 1. Random & 2. KI" << endl;
    int menu, stueck;
    hoelzchen = 15;
    cin >> menu;

    cout << endl;
    if(menu == 1) {
        cout  << endl << "Es werden Randomzahlen genommen." << endl << endl;
    } else if(menu == 2) {
        cout  << endl << "Der Computer berechnet seine Zahlen." << endl << endl;
    } else {
        cout  << endl << "Ungültige Eingabe." << endl << endl;
        return 1;
    }

    cout << "Es geht los!" << endl << endl;

    while(true) {
        cout << "Es sind noch " << hoelzchen << " Hölzchen im Spiel." << endl<< endl;
        //Spieler
        cout << "Wie viele willst du nehmen? ";
        cin >> stueck;
        if(stueck > 3) {
            stueck = 3;
        } else if(stueck < 1) {
            stueck = 1;
        }
        cout << "Du hast "  << stueck << " Hölzchen genommen." << endl;
        hoelzchen -= stueck;

        if(hoelzchen < 1) {
            cout << endl << endl << ">>>>>>>>>> Der Computer hat Gewonnen! <<<<<<<<<<" << endl << endl;
            break;
        }

        cout << "Es sind noch " << hoelzchen << " Hölzchen im Spiel." << endl<< endl;

        //Computer
        if(menu == 1) {
            stueck = rand() % 3 + 1;
        } else {
            if(hoelzchen > 13) {
                stueck = hoelzchen - 13;

            } else if(hoelzchen > 9) {
                stueck = hoelzchen - 9;

            } else if(hoelzchen > 5) {
                stueck = hoelzchen - 5;

            } else {
                stueck = hoelzchen - 1;

            }
            if(stueck > 3 || stueck < 1) {
                stueck = rand() % 3 + 1;
            }
        }

        cout << "Der Computer hat " << stueck << " Hölzchen genommen." << endl;
        hoelzchen -= stueck;
        if(hoelzchen < 1) {
            cout << endl << endl << ">>>>>>>>>> Du hast Gewonnen! <<<<<<<<<<" << endl << endl;
            break;
        }
    }
    system("pause");

}
