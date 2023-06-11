#include <iostream>
#include <unistd.h>
#include <fstream>
#include <locale>
#include <windows.h>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <conio.h>

#include "include/nlohmann/json.hpp"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
using json = nlohmann::json;

#include "classes/jstorry.class.cpp"
#include "classes/jcremove.class.cpp"


int getKey() {
newkey:
   int result = getch();
   if(result==0) {
      result = 256 + getch();
   }
   if(result == 224) {
        goto newkey;
   }
   return result;
}

void sendMessage(string text, int sleep_duration) {

    for(char& c : text) {
        cout << c;
        sleep_for(chrono::milliseconds(sleep_duration));
    }
}

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "C.UTF-8");

    //SetConsoleOutputCP(1252);
    SetConsoleCP(1252);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);

	//cout << "test:  5% x..................." << "\r";
	//cout.flush ();
	//sleep (1);

	JCRemove* jsc = new JCRemove();
	JStorry* js = new JStorry("storry.json");
    js->setNext("START");
    js->next();
    sendMessage(js->getText(), 50);

    //int time = js->getText().length() * 100;
    while(true) {
        js->next();
        sleep_for(2s);

        cout << endl << endl;
        sendMessage(js->getText(), 50);
        //time = js->getText().length() * 100;

        if(js->isChoise()) {
            sleep_for(chrono::milliseconds(100));

            cout << endl << endl;
            jsc->setPoint();

            int menu = 0;
            while(true) {
                int csize = js->getChoiseSize();
                for(int i=0;i<csize;i++) {
                    if(menu == i) {
                        SetConsoleTextAttribute(hConsole, 14);//8
                    } else {
                        SetConsoleTextAttribute(hConsole, 8);//8
                    }

                    cout << js->getChoise(to_string(i));
                    cout << " ";
                }

                int num = getKey();
                jsc->removeLine();
                if(num == 75) { //<
                    menu = menu == 0 ? menu = (csize-1) : menu-=1;;

                } else if(num == 77) { //>
                    menu = menu == (csize-1) ? menu = 0 : menu+=1;

                } else if(num == 13 || num == 32) { //Leer Enter
                    break;
                }

            }
            SetConsoleTextAttribute(hConsole, 14);
            sendMessage(js->getChoise(to_string(menu)), 25);

            js->setChoise(menu);

            SetConsoleTextAttribute(hConsole, 10);

            continue;
        }

    }

}
