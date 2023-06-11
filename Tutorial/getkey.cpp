#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int getKeyi() {
newkey:
   int result = getch();
   if(result==0) {
      result = 256 + getch();
   }
   if(result == 224) {
        goto newkey;
   }
   return result;
}
char getKeyc() {
   char result = getch();
   return result;
}
int main() {
    system("chcp 65001 > nul");

    while(true) {
        int key = getKeyi();
        cout << key << endl;
    }
}
