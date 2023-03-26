#include <iostream>

using namespace std;

bool islogin = false;
string
    masterpassword = "0000",    //Zugangspasswort
    option = "",                //Zwiwchenmerker für Option
    passwordlist[100][3],       //Liste aller Passwörter
    mvalue[2];                  //Zwiwchenmerker für Befehl

int fail = 0;

bool login(string input) {
    if(islogin) {
        return true;
    }
    if(input == masterpassword) {
        islogin = true;
        system("cls");
        cout << "Sie haben sich erfolgreich eingeloggt!" << endl;
        cout << "Nutze: help" << endl;
        option = "";
        fail = 0;
        return false;
    } else if(option == "login") {
        fail++;
        if(fail >= 3) {
            cout << "Das Passwort wurde zu oft falsch eingegeben!" << endl;
            cout << "Das Programm wird beendet!" << endl;
            exit(0);
            return false;
        }
        cout << "Das Passwort ist falsch!" << endl;
        option = "";
        return false;
    }
    cout << "Sie müsst sich erst einloggen mit: login <passwort>" << endl;
    return false;
}

bool setOption(string input) {
    if(option != ""){
        return false;
    }
    if(input == "login") {
        option = input;
        return true;
    } else if(input == "logout") {
        option = input;
        return false;
    } else if(input == "help") {
        option = input;
        return false;
    } else if(input == "setloginpw") {
        option = input;
        return true;
    } else if(input == "clear") {
        option = input;
        return false;
    } else if(input == "list") {
        option = input;
        return false;
    } else if(input == "delete") {
        option = input;
        return true;
    } else if(input == "add") {
        option = input;
        return true;
    }
    return false;
}

int getFreeSlot() {
    for(int i=0;i<100;i++) {
        if(passwordlist[i][0] == "") {
            return i;
        }
    }
    return -1;
}

int exist(string name) {
    for(int i=0;i<100;i++) {
        if(passwordlist[i][0] == name) {
            return true;
        }
    }
    return false;
}

bool command() {
    string input;
    cin >> input;

    if(input == "exit") {
        system("cls");
        return false;
    }

    if(setOption(input)) {
        return true;
    }

    if(!login(input)) {
        return true;
    }
    if(option == "logout") {
        islogin = false;
        system("cls");
        cout << "Sie haben sich erfolgreich ausgeloggt!" << endl;

    } else if(option == "setloginpw") {
        masterpassword = input;
        cout << "Ihr Passwort wurde erfolgreich geändert!" << endl;

    } else if(option == "list") {
        cout << string(40, '_') << endl;
        cout << "Name - Loginname - Passwort" << endl << endl;
        for(int i=0;i<100;i++) {
            if(passwordlist[i][0] == "") {
                continue;
            }
            cout << passwordlist[i][0] << " - " << passwordlist[i][1] << " - " << passwordlist[i][2] << endl;
        }
        cout << string(40, '_') << endl;
    } else if(option == "delete") {
        int found = -1;
        for(int i=0;i<100;i++) {
            if(passwordlist[i][0] != input) {
                continue;
            }
            found = i;
            break;
        }
        if(found > -1) {
            passwordlist[found][0] = "";
            passwordlist[found][1] = "";
            cout << "Die Daten wurde erfolgreich gelöscht!" << endl;

        } else {
            cout << "Es wurde keine Daten gefunden mit den Namen: " << input << "!" << endl;

        }

    } else if(option == "add") {
        if(mvalue[0] == "") {
            mvalue[0] = input;
            return true;
        } else if(mvalue[1] == "") {
            mvalue[1] = input;
            return true;
        }
        int slot = getFreeSlot();
        if(slot == -1) {
            cout << "Der Speicher von 100 Passwörtern ist voll!" << endl;
        } else {
            if(exist(mvalue[0])) {
                int i=1;
                while(true) {
                    string nname = mvalue[0];
                    nname.append(to_string(i++));
                    if(exist(nname)) {
                        continue;
                    }
                    mvalue[0] = nname;
                    break;
                }
            }
            passwordlist[slot][0] = mvalue[0];
            passwordlist[slot][1] = mvalue[1];
            passwordlist[slot][2] = input;
            mvalue[0] = "";
            mvalue[1] = "";
            cout << "Die Daten wurde erfolgreich eingefügt!" << endl;
        }

    } else if(option == "clear") {
        system("cls");

    } else if(option == "help") {
        cout << string(40, '_') << endl;
        cout << "Befehle:" << endl;
        cout << "logout \t\t\t- Ausloggen" << endl;
        cout << "setloginpw \t\t- Loginpasswort ändern" << endl;
        cout << "clear \t\t\t- Console clearen" << endl;
        cout << "list \t\t\t- Passwörter auflisten" << endl;
        cout << "add <name> <login> <pw> - Passwort hinzufügen" << endl;
        cout << "delete <name> \t\t- Passwort löschen" << endl;
        cout << "help \t\t\t- Befehle auflisten" << endl;
        cout << "exit \t\t\t- Programm beenden" << endl;
        cout << string(40, '_') << endl;

    } else {
        cout << "Befehl nicht gefunden..." << input << endl;
    }
    cin.ignore(128, '\n');
    option = "";
    return true;
}

int main() {
    system("chcp 65001 > nul"); //UTF-8 support

    cout << "Passwortmanager v1.0" << endl;
    cout << "Programm zum speichern von Passwörtern" << endl << endl;

    passwordlist[0][0] = "Test";
    passwordlist[0][1] = "Name";
    passwordlist[0][2] = "password";
    passwordlist[1][0] = "Name2";
    passwordlist[1][1] = "Name";
    passwordlist[1][2] = "password";

    while(command()) {
    }
}
