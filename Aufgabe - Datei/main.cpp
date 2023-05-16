#include <iostream>
#include <fstream>

using namespace std;

void command() {
}

int main() {
    system("chcp 65001 > nul"); //UTF-8 support

    cout << "Dateiverarbeitung v1.0" << endl;
    cout << "Programm zur Erstellung von Datein" << endl << endl;

    fstream f;
    f.open("index.html", ios::out);

    f << "Hallo Welt" << endl << "Test1";
    cout << endl << "Die Datei index.html wurde erstellt";
    f.close();


    f.open("index.html", ios::in);

    string line, line2;
    getline(f, line);
    getline(f, line2);
    cout << endl << line << endl << line2;

}
