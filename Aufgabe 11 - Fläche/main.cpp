#include <iostream>

#define pii 3,14156

using namespace std;

menu() {
    cout << "--- Menu ---" << endl << endl;

    cout << "1. Berechnung des Umfangs" << endl;
    cout << "2. Berechnung der Fläche" << endl;
    cout << "3. Programm beenden" << endl;
    cout << "Bitte wählen: " << endl;

    int num;
    cin >> num;

    if(num == 3) {
        exit(0);
    }

    cout << "Radius: ";

    float radius;
    cin >> radius;

    switch(num) {
        case 1:
            radius = pii * radius * 2;
            cout << endl << "Umfang: " << radius << endl << endl;
            break;
        case 2:
            radius = pii * radius * radius;
            cout << endl << "Fläche: " << radius << endl << endl;
            break;
    }
}

int main() {
    system("chcp 65001 > nul");

    cout << "Flächenrechner v1.0" << endl;
    cout << "Programm  dass den Umfang und die Fläche eines Kreises berechnen kann" << endl << endl;


    while(true) {
       menu();
    }

}
