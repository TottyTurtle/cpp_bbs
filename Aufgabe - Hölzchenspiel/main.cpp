#include <iostream>
#include <windows.h>
#include <thread>


using namespace std;
using namespace std::this_thread;

int sum = 15,
    player = 0,
    computer = 0,
    difficult = 1;
bool lastwinner = false;;

int optimalMove() {

    int cmove;
    if(sum > 13) {
        cmove = sum - 13;

    } else if(sum > 9) {
        cmove = sum - 9;

    } else if(sum > 5) {
        cmove = sum - 5;

    } else {
        cmove = sum - 1;

    }
    if(cmove > 3 || cmove < 1) {
        cmove -= rand() % 3 + 1;
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
    system("cls");


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
        computer += 1;
        lastwinner = false;
        gameLayout(2);
    } else {
        player += 1;
        lastwinner = true;
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

        msg = "Du nimmtst " + to_string(bet) + " Hölzchen.";
    } else {
        switch(difficult) {
            case 1:
                bet = rand() % 3 + 1;
                break;
            case 2:
                if((rand() % 10 + 1) <= 5) {
                    bet = rand() % 3 + 1;
                } else {
                    bet = optimalMove();
                }
                break;
            case 3:
                if((rand() % 10 + 1) <= 1) {
                    bet = rand() % 3 + 1;
                } else {
                    bet = optimalMove();
                }
                break;
        }
        bet = bet > 2 ? 3 : bet;
        bet = bet < 1 ? 1 : bet;
        bet = bet >= sum ? sum : bet;
        msg = "PC nimmt " + to_string(bet) + " Hölzchen.";
    }
    sum -= bet;

    if(checkWin(isplayer)) {
        return true;
    }

    gameLayout(0);
    cout << msg << endl;
    sleep_for(1s);
    return false;
}

int main() {
    system("chcp 65001 > nul"); //UTF-8 support
    srand (time(NULL));


    gameLayout(0);


    cout << "Wähle eine Schwierigkeit:" << endl;
    cout << "1. Leicht    2. Normal    3. Schwer" << endl << endl;


    cout << "Schwierigkeitsgrad Stufe: ";
    cin >> difficult;


    gameLayout(0);

    bool isplayer = false;
    if(difficult == 3) {
        isplayer = true;
    }
    while(true) {
        isplayer = !isplayer;
        if(play(isplayer)) {
            sum = 15;
            isplayer = lastwinner;
            gameLayout(0);
        }
    }

}
