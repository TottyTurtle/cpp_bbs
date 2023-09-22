#include <iostream>
#include <windows.h>

using namespace std;

int getRandom(int min, int max) {
    return rand()%((max + 1)-min)+min;
}

int main() {
    system("chcp 65001 > nul");
    cout << "Test" <<  endl;



    cout << "Wähle aus folgenden Punkten aus:" << endl;
    cout << "[r] Rechnen mit Tausendern" << endl;
    cout << "[s] Rechnen bis 10000" << endl;
    cout << "[b] Programm beenden" << endl;

    char menu;
    cin >> menu;

    if(menu == 'b') {
        exit(0);
    } else if(menu != 'r' && menu != 's') {
        cout << "Ungültige Eingabe" << endl;
        return 1;
    }

    cout << "Wie viele Aufgaben sollen berechnet werden?" << endl;
    int value;
    cin >> value;

    cout << "Welche Aufgaben sollen gestellt werden?" << endl;
    cout << "[+] Addition" << endl;
    cout << "[-] Subtraktion" << endl;
    char type;
    cin >> type;

    if(type != '+' && type != '-') {
        cout << "Ungültige Eingabe" << endl;
        return 1;
    }

    for(int i=0;i<value;i++) {
        int random1 = getRandom(menu == 's' ? 0 : 1000 , 10000);
        int random2 = getRandom(menu == 's' ? 0 : 1000 , 10000);
        cout << endl << "Aufgabe " << (i + 1) << endl;
        cout << random1 << " " << type << " " << random2 << " = ";

        int presult;
        cin >> presult;

        int result = type == '+' ? (random1 + random2) : (random1 - random2);
        if(presult ==  result) {
            cout << "Richtig! Das Ergebniss ist: " << result << endl;
        } else {
            cout << "Falsch! Das Ergebniss ist: " << result << endl;
        }
    }



}
