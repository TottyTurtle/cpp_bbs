#include <iostream>

using namespace std;

bool ask(string frage, string antwort) {
    string eingabe;

    cout << frage << endl;
    cin >> eingabe;

    if(eingabe != antwort) {
        cout << "Leider falsch!";
        return false;
    }
    cout << "Richtig!" << endl<< endl;
    return true;
}

int main() {
    system("chcp 65001 > nul");

    cout << "Aufgabe 1 v1.0" << endl;
    cout << "Programm zeigt geheimes Wort nach 3 Fragen" << endl << endl;

    cout << "Geben Sie die Richtigen Antworten um das geheime Wort zu erhalten." << endl << endl;


    if(!ask("Frage 1: Wie viel ist 2 + 2?", "4"))
       return 1;
    if(!ask("Frage 2: Welche Farbe hat das Wasser?", "blau"))
       return 1;
    if(!ask("Frage 3: Wo leben wir?", "deutschland"))
       return 1;


    cout << "Das geheime Wort ist \"Apfelbaum\"!" << endl<< endl;
}
