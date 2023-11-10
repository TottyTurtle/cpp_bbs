#import <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "HTMLtables 1.0" << endl << endl;

    cout << "Wie viele Zeilen soll die Tabelle haben?" << endl;

    int zeilen;
    cin >> zeilen;

    ofstream fout;
    fout.open("index.html",ios::out);
    fout << "<html>\n\t<header></header>\n\t<body>";
    fout << "\n\t<table border=\"4\">";
    for(int i=1;i<=zeilen;i++) {
        fout << "\n\t\t<tr><td>Zeile " << i << "</td></tr>";
    }
    fout << "\n\t</body>\n</html>";
    fout.close();

    cout << "Die Datei index.html wurde erstellt."<< endl << endl;
    system("pause");
}
