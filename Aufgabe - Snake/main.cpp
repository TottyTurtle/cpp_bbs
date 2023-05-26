#include <iostream>
#include <windows.h>
#include <thread>
#include <stdio.h>
#include <conio.h>


using namespace std;
using namespace std::this_thread;

int size_x=15, size_y=30;
int point_x=1, point_y=1;
int direction;

int getKey()
{
   int result = getch();
   if(result==0) {
      result = 256 + getch();
   }
   return result;
}

void layout() {
    system("cls");
    string top = "";
    for(int x=0;x<size_y;x++) {
        top += "═";
    }
    cout << "╔" << top << "╗" << endl;
    for(int x=0;x<size_x;x++) {
        cout << "║";
        for(int y=0;y<size_y;y++) {
            if(point_x == x && point_y == y) {
                cout << "X";
            } else {
                cout << " ";
            }
        }
        cout << "║" << endl;
    }
    cout << "╚" << top << "╝" << endl;
    cout << point_x << " " << point_y;

}
int main() {
    system("chcp 65001 > nul"); //UTF-8 support


    while(true) {
        layout();
        int key = getKey();

        switch(key) {
            case 119:
                point_x--;
                break;
            case 97:
                point_y--;
                break;
            case 115:
                point_x++;
                break;
            case 100:
                point_y++;
                break;
        }
    }
}


