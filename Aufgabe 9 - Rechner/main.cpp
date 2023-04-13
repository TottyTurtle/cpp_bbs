#include <iostream>
#include <conio.h>

#define cinclear; \
    cin.ignore(128, '\n'); \
    cin.clear();

#define endl2 endl << endl

using namespace std;


void rechner() {
    int num1, num2, sum,
        modulo = 0;
    char opr;

    cout << "Gib eine Zahl ein: " ;
    cin >> num1;
    cinclear;

    cout << "Gib eine Zahl ein: ";
    cin >> num2;
    cinclear;

    cout << "Gib eine Operator(+, -, *, /) an: ";
    cin >> opr;
    cinclear;

    switch(opr) {
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
            sum = num1 / num2;
            modulo = num1 % num2;
            break;
        default:
            cout << "Fehler: " << opr << " ist kein Operator" << endl2;
            return;
    }

    cout << endl2 << "Berechne: " << num1 << " " << opr << " " << num2 << " = " << sum;
    if(modulo > 0) {
        cout << " rest " << modulo;
    }
    cout << endl2;
}
int main() {
    cout << "Grundrechenprogramm v1.0" << endl;
    cout << "Programm mit 4 Grundrechenarten (+, -, *, /)" << endl2;

    while(true) {
        rechner();
        cout << "Weiter mit Enter" ;
        char var = _getch();
        system("cls");
    }
}
