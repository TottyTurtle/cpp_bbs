#include <iostream>
#include <unistd.h>
#include <fstream>
#include <locale>
#include <windows.h>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <conio.h>

#include "include/nlohmann/json.hpp" //Externer Include

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
using json = nlohmann::json;

#include "classes/jstorry.class.cpp" //Eigener Klasse Json Storry
#include "classes/jcremove.class.cpp" //Eigene Klasse Console Manipulation

int maincolor = 6, //Farbe für Text
    boxcolor = 12; //Farbe für Infobox

int getKey() { //Funktion rückgabe für Tastenanschlag
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

void sendMessage(string text, int sleep_duration) { //Nachricht als Zeichen in einer Geschwindigkeit ausgeben

    for(char& c : text) {
        cout << c;
        sleep_for(chrono::milliseconds(sleep_duration));
    }
}

string sloop(string text, int num) { //Anzahl an Sonderzeichen ausgeben
    string rtext = "";
    for(int i=0;i<num;i++) {
        rtext += text;
    }
    return rtext;
}

int main() {
    system("chcp 65001 > nul"); //UTF-8
    setlocale(LC_ALL, "C.UTF-8"); //UTF-8

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //HANDLE für Schriftfarbe ändern
    SetConsoleTextAttribute(hConsole, maincolor); //Schriftfarbe ändern

    //SetConsoleOutputCP(1252);
    SetConsoleCP(1252); //UTF-8

    SetConsoleTextAttribute(hConsole, 6); //Schriftfarbe ändern

    cout << "  _____ _            __  __            _   _               _____                     _ _ _   _" << endl;
    cout << " |_   _| |__   ___  |  \\/  | __ _ _ __| |_(_) __ _ _ __   | ____|_  ___ __   ___  __| (_) |_(_) ___  _ __  " << endl;
    cout << "   | | | '_ \\ / _ \\ | |\\/| |/ _` | '__| __| |/ _` | '_ \\  |  _| \\ \\/ / '_ \\ / _ \\/ _` | | __| |/ _ \\| '_ \\ " << endl;
    cout << "   | | | | | |  __/ | |  | | (_| | |  | |_| | (_| | | | | | |___ >  <| |_) |  __/ (_| | | |_| | (_) | | | |" << endl;
    cout << "   |_| |_| |_|\\___| |_|  |_|\\__,_|_|   \\__|_|\\__,_|_| |_| |_____/_/\\_\\ .__/ \\___|\\__,_|_|\\__|_|\\___/|_| |_|" << endl;
    cout << "                                                                     |_|" << endl;
    cout << endl;

    SetConsoleTextAttribute(hConsole, 14); //Schriftfarbe ändern

    cout << "Ein Spiel von Pierre Jentzsch" << endl;
    cout << endl;
    sleep_for(5s); //Warten
    system("cls"); //Console Leeren


	JCRemove* jsc = new JCRemove(); //Klasse laden für Consolen Manipulation
	JStorry* js = new JStorry("_mars.json"); //Klasse laden für Storry

    js->setNext("START"); //Auf Start setzen
    js->next(); //Nächsten Text laden

    if(js->isBox()) { //Abfrage Aktueller Text eine Box ist
        SetConsoleTextAttribute(hConsole, boxcolor); //Schriftfarbe ändern

        //Box ausgeben
        int slength = js->getText().length();
        cout << "┌─" << sloop("─", slength) << "─┐" << endl;
        cout << "│ " << js->getText() << " │" << endl;
        cout << "└─" << sloop("─", slength) << "─┘";

        SetConsoleTextAttribute(hConsole, maincolor); //Schriftfarbe ändern

    } else { //Wenn keine Box ist
        sendMessage(js->getCharacter()+ ": " + js->getText(), 50); //Text ausgeben
    }

    bool skip = false; //Varriable um sleep zu überspringen
    while(true) {
        js->next();//Nächsten Text laden

        if(!skip) {
            sleep_for(2s);
        }
        skip = false;

        cout << endl << endl;

        if(js->isBox()) { //Abfrage Aktueller Text eine Box ist
            SetConsoleTextAttribute(hConsole, boxcolor); //Schriftfarbe ändern

            //Box ausgeben
            int slength = js->getText().length();
            cout << "┌─" << sloop("─", slength) << "─┐" << endl;
            cout << "│ " << js->getText() << " │" << endl;
            cout << "└─" << sloop("─", slength) << "─┘";

            SetConsoleTextAttribute(hConsole, maincolor); //Schriftfarbe ändern

        } else { //Wenn keine Box
            if(js->getCharacter() == "Player") { //Antwort vom Spieler
                SetConsoleTextAttribute(hConsole, 14); //Schriftfarbe ändern
                sendMessage(js->getText(), 25); //Text ausgeben
                SetConsoleTextAttribute(hConsole, maincolor); //Schriftfarbe ändern

            } else { //Antwort vom Spiel
                sendMessage(js->getCharacter()+ ": " + js->getText(), 50); //Text ausgeben

            }
        }

        if(js->isChoise()) { //Ist eine Antwort enthalten
            sleep_for(chrono::milliseconds(100));

            jsc->setPoint(); //Consolen Manipulation Punkt setzen

            int menu = 0; //Variable für Ausgewählte Antwort

            while(true) {
                int csize = js->getChoiseSize(); //Anzahl Antworten anfordern

                cout << endl << endl;
                for(int i=0;i<csize;i++) //Antworten ausgeben
                    if(menu == i) {
                        SetConsoleTextAttribute(hConsole, 14); //Farbe setzen
                    } else {
                        SetConsoleTextAttribute(hConsole, 8); //Farbe setzen
                    }
                    cout << js->getChoise(to_string(i)); //Antworten ausgeben
                    cout << " ";
                }

                int num = getKey(); //Tastenanschlag anfordern
                jsc->removeLine(); //Consolen Manipulation bis zum letzten Punkt löschen

                //Menu Pfeiltasten Selektieren
                if(num == 75) { //<
                    menu = menu == 0 ? menu = (csize-1) : menu-=1;;

                } else if(num == 77) { //>
                    menu = menu == (csize-1) ? menu = 0 : menu+=1;

                } else if(num == 13 || num == 32) { //Leer Enter
                    break;
                }

            }

            skip = true; //Da Spielerantwort kein sleep nötig
            js->setChoise(menu); //Klasse die Antwort liefern um Weg zu bestimmen

            SetConsoleTextAttribute(hConsole, maincolor); //Farbe setzen

            continue;
        }

    }

}
