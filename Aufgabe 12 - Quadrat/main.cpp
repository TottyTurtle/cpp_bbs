#include <iostream>

using namespace std;

int main() {
    system("chcp 65001 > nul");

    cout << "Quadratgenerator v1.0" << endl;
    cout << "Programm das ein Sternchenquadrat beliebiger Größe ausgibt" << endl << endl;

    cout << "Welche Breite soll das Quadrat haben? ";

    int value;
    cin >> value;

    cout << endl;

    for(int x=0;x<value;x++) {
        for(int y=0;y<value;y++) {
            cout << "*";
        }
        cout << endl;
    }
}
