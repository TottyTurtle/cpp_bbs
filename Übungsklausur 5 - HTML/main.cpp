#import <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "HTMLtables 1.0" << endl << endl;

    cout << "Wie viele Zeilen soll die Tabelle haben?" << endl;

    int zeilen;
    cin >> zeilen;


    cout << "Wie viele Spalten soll die Tabelle haben?" << endl;

    int spalte;
    cin >> spalte;

    ofstream fout;
    fout.open("index.html",ios::out);
    fout << "<html>\n\t<header></header>\n\t<body>";

    fout << "\n\t\t<table border=\"4\">";

    for(int i=1;i<=zeilen;i++) {
        fout << "\n\t\t\t<tr>";
        for(int j=1;j<=spalte;j++) {
            fout << "\n\t\t\t\t<td>Zeile " << i << ", Spalte " << j << "</td>";
        }
        fout << "\n\t\t\t</tr>";
    }

    fout << "\n\t\t</table>";
    fout << "\n\t</body>\n</html>";
    fout.close();

    cout << "Die Datei index.html wurde erstellt."<< endl << endl;
    system("pause");
}
