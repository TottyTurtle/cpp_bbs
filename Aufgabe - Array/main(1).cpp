#include <iostream>

using namespace std;

int amount;
float measure[100];

setMeasurement() {
    cout << "Geben Sie die Gesamtzahl der Wiederstände an!" << endl;

    int resistance;
    cin >> resistance;
    cout << endl;

    cout << "Geben Sie an, wie viele davon fehlerhaft sind!" << endl;
    int fail;
    cin >> fail;
    cout << endl;

    cout << "Menü:" << endl;
    cout << "1 -> Weitere Werte eingeben" << endl;
    cout << "2 -> Eingaben auswerten" << endl;
    cout << "3 -> Programm beenden" << endl;
    int menu;
    cin >> menu;
    cout << endl;

    measure[amount] = fail * 100.0 / resistance;
    amount++;

    if(menu == 1) {
        setMeasurement();

    } else if(menu == 2) {
        float average = 0.0;
        for(int i=0;i<=amount;i++) {
            average += measure[i];
        }
        average = average / amount;
        cout << "Die Fehlerquote von " << amount << " Messung(en) beträgt " << average << "%" << endl;

        cout << endl << "Weitere Fehlerquoten berechnen? (j/n)" << endl;
        char enter;
        cin >> enter;
        if(enter == 'n'){
            exit(1);
        }
    } else if(menu == 3) {
        exit(1);
    }
}

int main() {
    system("chcp 65001 > nul"); //UTF-8 support

    cout << "Passwort v1.0" << endl;
    cout << "Arrays verwenden" << endl << endl;

    while(true) {

        amount = 0;
        setMeasurement();
    }

}


