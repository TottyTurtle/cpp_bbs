#include <iostream>

using namespace std;



int main() {
    system("chcp 65001 > nul");

    cout << "Aufgabe 3 v1.0" << endl;
    cout << "Programm Division von zwei Zahlen" << endl << endl;

    cout << "Geben die 2 Zahlen ein:";
    int num1, num2, sum, modulo;

    cin >> num1;
    cin >> num2;

    if(num1 == 0 || num2 == 0) {
        cout << endl << "Durch Null kann nicht geteilt werden!" << endl;
        return 1;
    }

    sum = num1 / num2;
    modulo = num1 % num2;

    cout << endl << "Das Ergebniss ist: " << sum;
    if(modulo > 0) {
        cout << " rest: " << modulo ;
    }
}
