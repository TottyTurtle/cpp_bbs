#include <iostream>

using namespace std;

void command() {
}

int main() {
    system("chcp 65001 > nul"); //UTF-8 support

    cout << "Passwort v1.0" << endl;
    cout << "Programm zur Abfrage eines Passworts" << endl << endl;



    string password;
    cin >> password;
    cout << password << endl;

    if(password == "test") {
        cout << "Das Passwort ist korrekt.";
    } else {
        cout << "Das Passwort ist falsch";
    }

}
