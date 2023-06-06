#include <iostream>
#include <windows.h>
#include <thread>
#include <stdio.h>
#include <conio.h>

//─ │  ┌  ┐  ┘└

using namespace std;
using namespace std::this_thread;

int size_x=15, size_y=30,
    point_x=1, point_y=1,
    direction, last_direction,
    snake_size = 10;
int snake[15][30][2];

int getKey()
{
   int result = getch();
   if(result==0) {
      result = 256 + getch();
   }
   return result;
}

string getHead() {
    if(direction == -2) {
        return "↑";
    } else if(direction == -1) {
        return "←";
    } else if(direction == 2) {
        return "↓";
    } else if(direction == 1) {
        return "→";
    }
    return "X";
}

int getBody() {
    if(direction == last_direction) {
        if(direction == -2 || direction == 2) {
            return 0;
        } else if(direction == -1 || direction == 1) {
            return 1;
        }
    } else if((last_direction == 1 && direction == -2) || (direction == -1 && last_direction == 2)) {
         return 2;
    } else if((last_direction == -2 && direction == -1) || (direction == 2 && last_direction == 1)) {
         return 3;
    } else if((last_direction == -1 && direction == 2) || (direction == 1 && last_direction == -2)) {
         return 4;
    } else if((last_direction == 2 && direction == 1) || (direction == -2 && last_direction == -1)) {
         return 5;
    }

    return 0;
}

string getBodySign(int number) {
    switch(number) {
        case 0:
            return "│";
            break;
        case 1:
            return "─";
            break;
        case 2:
            return "┘";
            break;
        case 3:
            return "┐";
            break;
        case 4:
            return "┌";
            break;
        case 5:
            return "└";
            break;

    }

    return "X";
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
                cout << getHead();
            } else if(snake[x][y][0] > 0) {
                if(snake[x][y][0] == snake_size) {
                    snake[x][y][1] = getBody();
                }
                cout << getBodySign(snake[x][y][1]);
                snake[x][y][0] --;
            } else {
                cout << " ";
            }
        }
        cout << "║" << endl;
    }
    cout << "╚" << top << "╝" << endl;
    cout << point_x << " " << point_y;
    snake[point_x][point_y][0] = snake_size;
}
int main() {
    system("chcp 65001 > nul"); //UTF-8 support

    direction = 1;
    last_direction = 1;

    for(int x=0;x<size_x;x++) {
        for(int y=0;y<size_y;y++) {
              snake[x][y][0] = 0;
              snake[x][y][1] = 0;
        }
    }

    while(true) {
        layout();

        if (kbhit()) {
            int key = getKey();

            switch(key) {
                case 119://links
                    last_direction = direction;
                    direction = -2;
                    break;
                case 97://oben
                    last_direction = direction;
                    direction = -1;
                    break;
                case 115://rechts
                    last_direction = direction;
                    direction = 2;
                    break;
                case 100://unten
                    last_direction = direction;
                    direction = 1;
                    break;
            }
        } else {
            last_direction = direction;
        }

        switch(direction) {
            case -2://links
                point_x--;
                break;
            case -1://oben
                point_y--;
                break;
            case 2://rechts
                point_x++;
                break;
            case 1://unten
                point_y++;
                break;
        }


        sleep_for(60ms);
    }
}


