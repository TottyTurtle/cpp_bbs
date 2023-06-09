#include <iostream>
#include <windows.h>
#include <thread>
#include <stdio.h>
#include <conio.h>

//─ │  ┌  ┐  ┘└

using namespace std;
using namespace std::this_thread;

string debug = "";
int size_x=15, size_y=30,       //Spielfeld
    point_x=1, point_y=1,       //Postion
    direction, last_direction,  //Richtung
    snake_size = 10,            //Snake länge
    snake[15][30][2];          //Snake


int getKey()
{
   int result = getch();
   if(result==0) {
      result = 256 + getch();
   }
   return result;
}

void setFood() {
renewfood:
    int posx = rand() % size_x,
        posy = rand() % size_x;

    if(snake[posx][posy][0] > 0) {
        goto renewfood;
    }
    snake[posx][posy][0] = 1;
    snake[posx][posy][1] = -1;

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
    int snake_add = 0;
    for(int x=0;x<size_y;x++) {
        top += "═";
    }
    cout << "╔" << top << "╗" << endl;
    for(int x=0;x<size_x;x++) {
        cout << "║";
        for(int y=0;y<size_y;y++) {
            if(point_x == x && point_y == y) {
                if(snake[x][y][1] == -1) {

                    snake[x][y][1] = 0;
                    snake_add = 1;
                    setFood();
                }
                cout << getHead();
            } else if(snake[x][y][1] == -1) {
                cout << "O";
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
    cout << point_x << " " << point_y << " Debug: " << debug;

    snake_size += snake_add;
    snake[point_x][point_y][0] = snake_size;
}
int main() {
    system("chcp 65001 > nul"); //UTF-8 support
    srand (time(NULL));

    direction = 1;
    last_direction = 1;

    for(int x=0;x<size_x;x++) {
        for(int y=0;y<size_y;y++) {
              snake[x][y][0] = 0;
              snake[x][y][1] = 0;
        }
    }
    setFood();
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
        if(point_x >= size_x) {
            point_x = 0;
        } else if(point_x < 0) {
            point_x = size_x - 1;
        }
        if(point_y >= size_y) {
            point_y = 0;
        } else if(point_y < 0) {
            point_y = size_y - 1;
        }
        debug = to_string(snake[point_x][point_y][1]) + "";

        if(snake[point_x][point_y][0] > 0) {
            int num = snake[point_x][point_y][0];
            for(int x=0;x<size_x;x++) {
                for(int y=0;y<size_y;y++) {
                    if(snake[x][y][1] < 0) {
                        continue;
                    }
                    if(snake[x][y][0] < num) {
                        snake[x][y][0] = 0;
                        snake[x][y][1] = 0;
                    }

                }
            }
        }

        sleep_for(60ms);
    }
}


