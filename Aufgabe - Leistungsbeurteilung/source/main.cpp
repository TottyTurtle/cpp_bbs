#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <map>
#include <iterator>
#include <fstream>
#include <windows.h>
#include <vector>
#include <regex>
#include <dirent.h>
#include <fstream>
#include <locale>

#include "include/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

#include "function.cpp"
#include "classes/menu.class.cpp"
#include "classes/exam.class.cpp"
#include "menu/menuCreate.cpp"


Menu menu;
void initMenu() {
    menu.add("create", "Erstellen");
    menu.add("load", "Laden");
    menu.add("exit", "Beenden");

    init_menuCreate();
}

void systemExit() {
    system("cls");
    cout << endl << "> > > > > Programm wird beendet < < < < <" << endl;
    exit(0);
}

void menuLoad() {
    Menu loadmenu;
    DIR *hdir;
    struct dirent *entry;

    hdir = opendir("exam/");
    do{
        entry = readdir(hdir);
        if (entry) {
            if(isFile(entry->d_name)) {
                loadmenu.add(entry->d_name, entry->d_name);
            }
        }
    } while (entry);
    closedir(hdir);

    loadmenu.show("Wähle eine Datei aus:");
    while(true) {
        int key = getKey();
        if(key == 27) { //ESC
           break;
        } else if(key == 72) {
            loadmenu.change(-1);
        } else if(key == 80) {
            menuCreate(loadmenu.getKey());
            break;
        }

        loadmenu.show("Wähle eines dieser Punkte aus:");
    }
}

void enterMenu() {
    if(menu.getKey() == "create") {
        menuCreate("");
    } else if(menu.getKey() == "load") {
        menuLoad();
    } else if(menu.getK            loadmenu.change(1);
        } else if(key == 13) {
ey() == "exit") {
        systemExit();
    }
}

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "C.UTF-8");

    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);

    locale::global(locale(""));

    cout << " _        _    _                     _           _           _ _     " << endl;
    cout << "| |   ___(_)__| |_ _  _ _ _  __ _ __| |_____ _ _| |_ _ _ ___| | |___ " << endl;
    cout << "| |__/ -_) (_-<  _| || | ' \\/ _` (_-< / / _ \\ ' \\  _| '_/ _ \\ | / -_)" << endl;
    cout << "|____\\___|_/__/\\__|\\_,_|_||_\\__, /__/_\\_\\___/_||_\\__|_| \\___/_|_\\___|" << endl;
    cout << "         Version 1.0        |___/       by Pierre Jentzsch" << endl;
    cout << endl << "Navigiere mit ↑, ↓, Enter, ESC"<< endl << endl;

    system("pause");

    initMenu();
    menu.show("Hauptmenu \n\nWähle eines dieser Punkte aus:");

    while(true) {
        int key = getKey();
        if(key == 27) { //ESC
            systemExit();
        } else if(key == 72) {
            menu.change(-1);
        } else if(key == 80) {
            menu.change(1);
        } else if(key == 13) {
            enterMenu();
        }

        menu.show("Hauptmenu \n\nWähle eines dieser Punkte aus:");
    }

}
