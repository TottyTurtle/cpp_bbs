#include <iostream>
#include <fstream>
using namespace std;


int main() {

    cout << ":::Notenberechnung 1.0:::" << endl << endl;

    char menu;
    int percent_m = 30,
        percent_s = 40,
        percent_l = 30;

        string name[64];
        int note_m[64],
            note_s[64],
            note_l[64];



        int index =  0;

    do {

        cout << "Menu:" << endl;
        cout << string(30,'.') << endl;
        cout << "G -> Gewichtung festlegen" << endl;
        cout << "S -> Schulnoten eingeben" << endl;
        cout << "B -> Noten in Datei speichern" << endl;
        cout << "E -> Programm beenden" << endl;
        cout << string(30,'.') << endl;

        cin >> menu;

        switch(menu) {
            case 'G':
            case 'g':
                cout << "Geben Sie die Prozente ein fuer Muendlich: ";
                cin >> percent_m;

                cout << "Geben Sie die Prozente ein fuer Schriftlich: ";
                cin >> percent_s;

                cout << "Geben Sie die Prozente ein fuer Letze Halbjahr: ";
                cin >> percent_l;

                break;
            case 'S':
            case 's':
                cout << "Geben Sie den Namen des Schülers ein: ";
                cin >> name[index];

                cout << "Geben Sie die Muendliche Note ein: ";
                cin >> note_m[index];

                cout << "Geben Sie die Schriftliche Note ein: ";
                cin >> note_s[index];

                cout << "Geben Sie die letzte Halbjahr Note ein: ";
                cin >> note_l[index];

                index = index + 1;
                break;
            case 'B':
            case 'b': {
                ofstream fout;
                fout.open("text.txt",ios::out);
                cout << "Title " <<  endl;
                fout << "Title " <<  endl;
                for(int d=0; d<index; d++) {

                    float sum = percent_m / 100.0 * note_m[d];
                    sum += percent_s / 100.0 * note_s[d];
                    sum += percent_l / 100.0 * note_l[d];



                    cout << name[d] << ": " << sum <<  endl;
                    fout << name[d] << ": " << sum <<  endl;
                }
                fout.close();

                break;
            }
            case 'E':
            case 'e':
                break;
        }


    } while(menu != 'e');

}


