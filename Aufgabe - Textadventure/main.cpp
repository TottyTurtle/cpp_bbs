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


int getKey() {
   int result = getch();
   if(result==0) {
      result = 256 + getch();
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

	JStorry* js = new JStorry("storry.json");
    js->setNext("START");
    js->next();
    sendMessage(js->getText(), 50);

    int time = js->getText().length() * 100;
    while(true) {
        js->next();
        sleep_for(chrono::milliseconds(time));



        cout << endl << endl;
        sendMessage(js->getText(), 50);
        time = js->getText().length() * 100;

        if(js->isChoise()) {
            sleep_for(chrono::milliseconds(100));
            cout << endl << endl;
            SetConsoleTextAttribute(hConsole, 14);
            cout << js->getChoise("0");
            cout << " ";
            SetConsoleTextAttribute(hConsole, 8);
            cout << js->getChoise("1");
            cout << "\r";
            int num = getKey();
            continue;
        }

    }




}
