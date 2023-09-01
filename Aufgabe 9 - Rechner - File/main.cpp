#include <iostream>
#include <fstream>
#include <conio.h>

#define cinclear; \
    cin.ignore(128, '\n'); \
    cin.clear();

#define endl2 endl << endl

using namespace std;

fstream file;

void rechner() {
    int num1, num2, sum,
        modulo = 0;
    char op;

    cout << "Gib eine Zahl ein: " ;
    cin >> num1;
    //cinclear;

    cout << "Gib eine Operator(+, -, *, /) an: ";
    cin >> op;
    //cinclear;

    cout << "Gib eine Zahl ein: ";
    cin >> num2;
    cinclear;

    switch(op) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            sum = num1 - num2;
            break;
        case '*':
            sum = num1 * num2;
            break;
        case '/':
            if(num2 == 0) {
                cout << "Fehler: Nicht durch 0 Teilbar" << endl2;
                return;
            }

            sum = num1 / num2;
            modulo = num1 % num2;
            break;
        default:
            cout << "Fehler: " << op << " ist kein Operator" << endl2;
            return;
    }

    file.open("ergebnis.txt", ios::out);
    cout << endl2 << "Berechne: " << num1 << " " << op << " " << num2 << " = " << sum;
    file << num1 << " " << op << " " << num2 << " = " << sum;
    if(modulo > 0) {
        cout << " rest " << modulo;
        file << " rest " << modulo;
    }
    cout << endl2;
    file.close();
}

int main() {
    cout << "Grundrechenprogramm v1.0" << endl;
    cout << "Programm mit 4 Grundrechenarten (+, -, *, /)" << endl2;

    file.open("ergebnis.txt", ios::in);

    string line;
    getline(file, line);
    cout << "Letzte Berechnung war: " << line << endl2;
    file.close();

    while(true) {
        rechner();
        cout << "Weiter mit Enter" ;
        char var = _getch();
        system("cls");
    }
}
