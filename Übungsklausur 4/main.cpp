#include <iostream>
#include <fstream>
using namespace std;


int main() {

    system("CHCP 65001 < nul");

    cout << ":::NOTENBERECHNUNG 1.0:::" << endl << endl;

    char menu;

    int weight_m = 0,
        weight_s = 0,
        weight_h = 0,
        index = 0,
        note_m[64],
        note_s[64],
        note_h[64];

    string user[64];

    do {

        cout << "..........................." << endl;
        cout << "Menü:" << endl;
        cout << "" << endl;
        cout << "G -> Gewichtung festlegen" << endl;
        cout << "S -> Schulnote eingeben" << endl;
        cout << "B -> Note in Datei speichern" << endl;
        cout << "E -> Programm beenden" << endl;
        cout << "..........................." << endl;

        cin >> menu;


        switch(menu) {
            case 'g':
            case 'G': {
                cout << "Geben Sie die Prozente ein für 'Mündliche':" << endl;
                cin >> weight_m;
                cout << "Geben Sie die Prozente ein für 'Schriftliche':" << endl;
                cin >> weight_s;
                cout << "Geben Sie die Prozente ein für 'letztes Halbjahr':" << endl;
                cin >> weight_h;
                break;
            }
            case 's':
            case 'S': {
                string name;
                cout << "Geben Sie den Namen des Schülers ein:" << endl;
                cin >> user[index];
                cout << "Note Mündliche:" << endl;
                cin >> note_m[index];
                cout << "Note Schriftliche:" << endl;
                cin >> note_s[index];
                cout << "Note vom letzten Halbjahr:" << endl;
                cin >> note_h[index];
                index++;

                break;
            }
            case 'b':
            case 'B': {

                fstream file;

                file.open("noten.txt", ios::out);
                file << "Berechnung der Gesamtnoten:" << endl << endl;
                cout << "Berechnung der Gesamtnoten:" << endl << endl;
                for(int i=0;i<index;i++) {

                    double gesnote =  weight_m / 100.0 * note_m[i];
                    gesnote += weight_s / 100.0 * note_s[i];
                    gesnote +=  weight_h / 100.0 * note_h[i];

                    file << user[i] << " " << gesnote << endl;
                    cout << user[i] << " " << gesnote << endl;
                }


                file.close();
                cout << "Datei wurde erstellt." << endl;
                break;
            }
            case 'e':
            case 'E': {

                break;
            }
            default: {
                cout << "Ungültige eingabe" << endl;
            }

        }

    } while(menu != 'e');
}
