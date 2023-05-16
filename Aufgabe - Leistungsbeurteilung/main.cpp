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

#include "include/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

#include "function.cpp"
#include "classes/menu.class.cpp"
#include "classes/exam.class.cpp"
#include "menu/menuCreate.cpp"

#define cmd(var) var()

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
            loadmenu.change(1);
        } else if(key == 13) {
            menuCreate(loadmenu.getKey());
            break;
        }

        loadmenu.show("Wähle eines dieser Punkte aus:");
        cout << key << endl;
    }
}

void enterMenu() {
    if(menu.getKey() == "create") {
        menuCreate("");
    } else if(menu.getKey() == "load") {
        menuLoad();
    } else if(menu.getKey() == "exit") {
        systemExit();
    }
}

int main() {
    system("chcp 65001 > nul");
    initMenu();
    menu.show("Wähle eines dieser Punkte aus:");

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

        menu.show("Wähle eines dieser Punkte aus:");
        //cout << key << endl;
    }

}
