#include <iostream>
#include <windows.h>

using namespace std;

char types[4] = {'+', '-', '*', '/'};

int getRNumber(int min, int max) {
    return (rand()%((max + 1)-min))+min;
}

void tasks() {

newtype:
    cout << "..........................." << endl;
    cout << "Welche aufgaben sollen berechnen werden:" << endl;
    cout << "" << endl;
    cout << "+ -> Addition" << endl;
    cout << "- -> Subtraktion" << endl;
    cout << "* -> Multiplikation" << endl;
    cout << "/ -> Division" << endl;
    cout << "A -> Gemischt" << endl;
    cout << "E -> Hauptmenu" << endl;
    cout << "..........................." << endl;

    char type;
    cin >> type;
    type = tolower(type);

    if(type == 'E') {
        return;
    }
    if(type != '+' && type != '-' && type != '*' && type != '/' && type != 'a') {
        cout << "Ungültige Eingabe" << endl << endl;
        goto newtype;
        return;
    }

newvalue:
    cout << "Gib die Menge der Aufgaben an:" << endl;

    int value;
    cin >> value;

    if(value < 1) {
        cout << "Ungültige Eingabe" << endl << endl;
        goto newvalue;
        return;
    }

    for(int i=1;i<=value;i++) {
        char mtype = type == 'a' ? types[getRNumber(0,3)] : type;
        cout << "Aufgabe " << i << " von " << value << endl;

        int num_1 = getRNumber(1,9), num_2 = getRNumber(1,9);
        int num_max = max(num_1, num_2);
        int num_min = min(num_1, num_2);
        cout << num_max << " " << mtype << " " << num_min << " = ";

        float isum;
        cin >> isum;

        float sum;
        switch(mtype) {
        case '+':
            sum = num_max + num_min;
            break;
        case '-':
            sum = num_max - num_min;
            break;
        case '*':
            sum = num_max * num_min;
            break;
        case '/':
            sum = num_max / num_min;
            break;

        }

        if(isum  != sum) {
            cout << "Falscher Wert: " << sum << endl << endl;

        } else {
            cout << "Richtig!!" << endl << endl;

        }
    }

}

void loop() {
    cout << "..........................." << endl;
    cout << "Menü:" << endl;
    cout << "" << endl;
    cout << "A -> Aufgaben rechnen" << endl;
    cout << "E -> Programm beenden" << endl;
    cout << "..........................." << endl;
    char menu;
    cin >> menu;
    menu = tolower(menu);

    switch(menu) {
        case 'a':
            tasks();
            break;
        case 'e':
            exit(1);
            break;

    }
}
int main() {
    system("chcp 65001 < nul");
    cout << "Matheübungsprogramm für Grundschüler v1.0" << endl << endl;

    while(true) {
        loop();
    }

}
