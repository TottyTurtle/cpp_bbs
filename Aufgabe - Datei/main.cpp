#include <iostream>
#include <fstream>

using namespace std;

void command() {
}

int main() {
    system("chcp 65001 > nul"); //UTF-8 support

    cout << "Dateiverarbeitung v1.0" << endl;
    cout << "Programm zur Erstellung von Datein" << endl << endl;
^
    fstream file;
    file.open("index.html", ios::out);

    file << "Hallo Welt" << endl << "Test1";
    cout << endl << "Die Datei index.html wurde erstellt";
    file.close();


    file.open("index.html", ios::in);

    string line, line2;
    getline(file, line);
    getline(file, line2);
    cout << endl << line << endl << line2;

}
