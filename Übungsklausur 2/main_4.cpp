#include <iostream>

using namespace std;


int main() {
    system("chcp 65001 > nul");

    cout << "Aufgabe 4 v1.0" << endl;
    cout << "Programm das Bodymassindex errechnet" << endl << endl;

    float bmi, height, weight;


    cout << "Geben Sie ihr Körpergewicht in kg an: ";
    cin >> weight;

    cout << endl << "Geben Sie ihre Körpergröße in cm an: ";
    cin >> height;
    height = height / 100;
    bmi = weight/(height*height);
    cout << endl << "Dein BMI liegt bei " << bmi << endl;

    if(16 > bmi) {
        cout << "Du hast Starkes Untergewicht" << endl;
    } else if(bmi >= 16 && 16.9 >= bmi) {
        cout << "Du hast Mäßiges Untergewicht" << endl;
    } else if(bmi >= 17 && 18.4 >= bmi) {
        cout << "Du hast Leichtes Untergewicht" << endl;
    } else if(bmi >= 18.5 && 24.9 >= bmi) {
        cout << "Du hast Normalgewicht" << endl;
    } else if(bmi >= 25 && 29.9 >= bmi) {
        cout << "Du hast Präadiposias" << endl;
    } else if(bmi >= 30 && 34.9 >= bmi) {
        cout << "Du hast Adipositas Grad |" << endl;
    } else if(bmi >= 35 && 39.9 >= bmi) {
        cout << "Du hast Adipositas Grad ||" << endl;
    } else if(bmi >= 40) {
        cout << "Du hast Adipositas Grad |||" << endl;

    }
}
