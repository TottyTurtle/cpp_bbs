#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main() {
    system("chcp 65001 > nul"); //UTF-8 support
    cout << "Passwort:" << endl;

    string input;
	for(char c; (c=getch())!='\n' && c!='\r'; input+=c);

    char c = getch();
    cout << c;
}

