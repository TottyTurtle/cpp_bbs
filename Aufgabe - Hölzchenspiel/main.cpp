#include <iostream>
#include<windows.h>

using namespace std;

int sum = 15;
int difficult = 1;

int play(bool isplayer) {
    int bet;
    if(isplayer) {
        cout << "Wie viele willst du nehmen?" << endl;

        cin >> bet;
        cout << "Du nimmst " << bet << " Hölzchen." << endl;
    } else {
        cout << "PC nimmt " << 2 << " Hölzchen." << endl;
        bet = 2;
        sleep(2);
    }
    sum -= bet;

    cout << endl << sum << " Hölzchen sind noch im Spiel." << endl;
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
    bool isplayer = false;
    while(true) {
        isplayer = !isplayer;
        play(isplayer);
    }

}
