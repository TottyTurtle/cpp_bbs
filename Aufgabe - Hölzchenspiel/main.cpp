#include <iostream>

using namespace std;

int sum = 15;
int difficult = 1;


int npc() {
    cout << string(22, '_');
    cout << "PC nimmst " << 2 << " Hölzchen." << endl;
    sum -= 2;
    cout << endl<< "Es sind noch " << sum << " im Spiel." << endl;
}

int player() {
    cout << string(22, '_');
    cout << endl<< "Wie viele willst du nehmen?" << endl;
    int bet;
    cin >> bet;
    cout << "Du nimmst " << bet << " Hölzchen." << endl;
    sum -= bet;
    cout << "Es sind noch " << sum << " im Spiel." << endl;
}

int main() {
    system("chcp 65001 > nul"); //UTF-8 support

    cout << "Hölzchenspiel v1.0" << endl;
    cout << "Spiel ums letzte Hölzchen" << endl << endl;

    cout << "Wähle eine Schwierigkeit:" << endl;
    cout << "1. Leicht" << endl;
    cout << "2. Normal" << endl;
    cout << "3. Schwer" << endl;


    cout << "Schwierigkeitsgrad Stufe: ";
    cin >> difficult;

    cout << "15 Hölzchen sind noch im Spiel." << endl;

    while(true) {
        player();
        npc();
    }

}
