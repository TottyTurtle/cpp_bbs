#include <iostream>
#include <string>
using namespace std;

#define str_replace(stext, sfind, sreplace) stext.find(sfind) > sizeof(stext) ? stext :stext.replace(stext.find(sfind), sizeof(sfind)-1, sreplace)


/*
    str_replace(stext, sfind, sreplace)
    Parameter:
     [string] stext - Text indem eine Variable ersetzt wird
     [string] sfind - Variable die ersetzt wird
     [string] sreplace - Variable die eingesetzt wird
*/

string tinput = "Eingabe:\t";
string tfrom = "Vorgänger\tNr. {nr}:";
string tafter = "Nachfolger\tNr. {nr}:";

int getInput(string text) {
newinput:
    cout << text;
    int value;
    cin >> value;

    if(cin.fail()) {
        cin.clear();
        cin.ignore(128, '\n');

        cout << "Ungültige Eingabe!" << endl;
        goto newinput;
    }
    return value;
}



int main() {
    system("chcp 65001 > nul"); //UTF-8 support

    cout << "Rechner v1.0" << endl;
    cout << "Programm die drei Vorgänger und die drei Nachfolger berechnet" << endl << endl;

    int value = getInput("Geben Sie eine Zahl ein, zu der Vorgänger und Nachfolger berechnet werden soll: ");

    cout << endl;

    for(int i=-3;i<=3;i++) {
        int nr = i < 0 ? i * -1 : i; //i Wert Positiv setzen
        int sum = value + i; //Vorgänger udn Nachfolger berechnen

        string text = i == 0 ? tinput : i < 0 ? tfrom : tafter; //Template abfragen
        text = str_replace(text, "{nr}", to_string(nr)); //Template Variable setzen

        cout << text << "\t" << sum << endl;
    }


}
