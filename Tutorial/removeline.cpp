#include <iostream>
#include <unistd.h>
#include <fstream>
#include <locale>
#include <windows.h>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <conio.h>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
    COORD pos={0, 0};
void gotoxy (COORD pos)
{

    cout.flush ();
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), pos);
}
void merker() {
    HANDLE handle=GetStdHandle (STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;

    if (GetConsoleScreenBufferInfo(handle, &info))
    {
        pos=info.dwCursorPosition;
    }

}
void clrscr ()
{
    HANDLE handle=GetStdHandle (STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;


    DWORD dw;

    cout.flush ();
    GetConsoleScreenBufferInfo (handle, &info);

    cout.flush ();
    FillConsoleOutputAttribute (handle, info.wAttributes, info.dwSize.X*info.dwSize.Y, pos, &dw);
    cout.flush ();
    FillConsoleOutputCharacter (handle, ' ', info.dwSize.X*info.dwSize.Y, pos, &dw);

    gotoxy (pos);
}
int main() {
    system("chcp 65001 > nul");
    cout << "tart" << endl << endl;
    merker();
    cout << "test:  1 % x...................X";
    cout << "test:  1 % x...................X";
    cout << "test:  1 % x...................X";
    cout << "test:  1 % x...................X";
    clrscr ();
    merker();
    cout << "test:  2 % x...................X";


}
