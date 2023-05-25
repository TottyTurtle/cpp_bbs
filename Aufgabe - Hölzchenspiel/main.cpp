#include <iostream>
#include <windows.h>
#include <thread>


using namespace std;
using namespace std::this_thread;

int sum = 15,
    player = 0,
    computer = 0,
    difficult = 1;


int optimalMove() {

    if ((sum - 1) % 4 == 0) {
        return 1;
    }


    int cmove = 0;
    for (int i = 1; i <= 3; i++) {
        if ((sum - i) % 4 == 0) {
            cmove = i;
            break;
        }
    }
    return cmove;
}


string numberToString(int num, string ch) {
    if(num < 10) {
        return ch + to_string(num);
    }

    return to_string(num);
}

void gameLayout(int type) {


    cout << "                                 Y\\     /Y" << endl;
    cout << "                                 | \\ _ / |" << endl;
    cout << "         _____                   | =(_)= |" << endl;
    cout << "     ,-~\"     \"~-.              ,-~\/^ ^\/~-." << endl;
    cout << "   ,^ ___     ___ ^.         ,^ ___     ___ ^." << endl;
    cout << "  / .^   ^. .^   ^. \\       / .^   ^. .^   ^. \\" << endl;
    cout << " Y  l    O! l    O!  Y     Y  lo    ! lo    !  Y" << endl;
    cout << " l_ `.___.' `.___.' _[     l_ `.___.' `.___.' _[" << endl;
    cout << " l^~\"-------------\"~^I     l^~\"-------------\"~^I" << endl;
    cout << "┌───────────────────────────────────────────────┐" << endl;
    cout << "│   Hölzchenspiel   Spiel ums letzte Hölzchen   │" << endl;
    cout << "├────────────────────┬─────┬────────────────────┤" << endl;

    if(type == 1) {
        cout << "│      ,--.   ,--.,--.,--.  ,--.,--.  ,--.      │" << endl;
        cout << "│      |  |   |  ||  ||  ,'.|  ||  ,'.|  |      │" << endl;
        cout << "│      |  |.'.|  ||  ||  |' '  ||  |' '  |      │" << endl;
        cout << "│      |   ,'.   ||  ||  | `   ||  | `   |      │" << endl;
        cout << "│      '--'   '--'`--'`--'  `--'`--'  `--'      │" << endl;

    } else if(type == 2) {
        cout << "│       ,--.    ,-----.  ,---.  ,------.        │" << endl;
        cout << "│       |  |   '  .-.  ''   .-' |  .---'        │" << endl;
        cout << "│       |  |   |  | |  |`.  `-. |  `--,         │" << endl;
        cout << "│       |  '--.'  '-'  '.-'    ||  `---.        │" << endl;
        cout << "│       `-----' `-----' `-----' `------'        │" << endl;

    } else {
        cout << "│                    ╘ " << numberToString(sum, "0") << "x ╛                    │" << endl;
        cout << "│                                               │" << endl;
        string layout = "│  ";
        for(int i=0;i<sum;i++) {
            layout += "║  ";
        }
        for(int i=sum;i<15;i++) {
            layout += "   ";
        }
        layout += "│";
        cout << layout << endl;
        cout << layout << endl;
        cout << "│                                               │" << endl;
    }


    cout << "├──────────────────────┬────────────────────────┤" << endl;
    cout << "│      Player: " << numberToString(player, " ") << "      |      Computer: " << numberToString(computer, " ") << "      │" << endl;
    cout << "└──────────────────────┴────────────────────────┘" << endl;

}

bool checkWin(bool isplayer) {
    if(sum > 0) {
        return false;
    }
    if(isplayer) {
        system("cls");
        gameLayout(2);
    } else {
        system("cls");
        gameLayout(1);
    }
    system("pause");
    return true;
}

bool play(bool isplayer) {
    string msg;
    int bet;
    if(isplayer) {
        cout << "Du bist am zug, wie viele willst du nehmen?" << endl;

        cin >> bet;
        bet = bet > 2 ? 3 : bet;
        bet = bet < 1 ? 1 : bet;
        bet = bet >= sum ? sum : bet;
        player += bet;

        msg = "Du nimmtst " + to_string(bet) + " Hölzchen.";
    } else {
        switch(difficult) {
            case 1:
                bet = rand() % 3 + 1;
                bet = bet >= sum ? sum : bet;
                break;
            case 2:
            case 3:
                bet = optimalMove();
                break;
        }
        computer += bet;
        msg = "PC nimmt " + to_string(bet) + " Hölzchen.";
    }
    sum -= bet;

    if(checkWin(isplayer)) {
        return true;
    }

    system("cls");
    gameLayout(0);
    cout << msg << endl;
    sleep_for(1s);
    return false;
}

int main() {
    system("chcp 65001 > nul"); //UTF-8 support
    srand (time(NULL));


    gameLayout(0);

    cout << "Hölzchenspiel v1.0" << endl;
    cout << "Spiel ums letzte Hölzchen" << endl << endl;

    cout << "Wähle eine Schwierigkeit:" << endl;
    cout << "1. Leicht    2. Normal    3. Schwer" << endl << endl;


    cout << "Schwierigkeitsgrad Stufe: ";
    cin >> difficult;


    system("cls");
    gameLayout(0);

    bool isplayer = false;
    if(difficult == 3) {
        isplayer = true;
    }
    while(true) {
        isplayer = !isplayer;
        if(play(isplayer)) {
            return 1;
        }
    }

}
