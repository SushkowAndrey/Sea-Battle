#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "Other_Fun.h"

using namespace std;
///////////////////////////////функции хода игрока/компьютера////////////////////////////////////////////
//функция хода игрока против компьютера
int HodIgr(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "Укажите первую координату (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e'
                && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату (строка) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
        return 1;   //для повторного удара в случае истины при попадании в однопалубный корабль K
    }
    else if (arr[x][y] == 'D') {
        arr[x][y] = 'O';
        return 2;   //для повторного удара в случае истины при попадании в двухпалубный корабль DD
    }
    else if (arr[x][y] == 'G') {
        arr[x][y] = 'O';
        return 3;   //для повторного удара в случае истины при попадании в двухпалубный корабль GG
    }
    else if (arr[x][y] == 'R') {
        arr[x][y] = 'O';
        return 4;   //для повторного удара в случае истины при попадании в двухпалубный корабль RR
    }
    else if (arr[x][y] == 'T') {
        arr[x][y] = 'O';
        return 5;   //для повторного удара в случае истины при попадании в трехпалубный корабль TTT
    }
    else {
        arr[x][y] = '*';
        return 0;
    }
}

//функция хода компьютера
int HodKomp(char arr[SIZE][SIZE], int& x, int& y, bool Ship_DD, bool Ship_GG, bool Ship_RR, bool Ship_TTT, int &Сoordinate_3_TTT)
{
    //если булевая переменная ложная, то компьютер наносит рандомный удар
    if (!Ship_DD && !Ship_GG && !Ship_RR && !Ship_TTT) {
        bool Result_vybora = false;
        do {
            do {
                x = rand() % 10;               //строка
            } while (x < 0 || x > 9);
            do {
                y = rand() % 10;              //столбец
            } while (y < 0 || y > 9);
            if (arr[x][y] == '*') Result_vybora = false;
            // цикл на проверку подбитых кораблей, тк корабли на расстоянии 1 клетки друг от друга вокруг подбитых кораблей на одну клетку нет других кораблей
            else {
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        if (arr[x + i][y + j] == 'O') {
                            Result_vybora = false;
                            break;
                        }
                        else Result_vybora = true;
                    }
                    if (!Result_vybora) break;
                }
            }
        } while (!Result_vybora); 
        if (arr[x][y] == 'K') {
            arr[x][y] = 'O';
            return 1;   //для повторного удара в случае истины при попадании в однопалубный корабль
        }
        else if (arr[x][y] == 'D') {
            arr[x][y] = 'O';
            return 2;   //для повторного удара в случае истины при попадании в двухпалубный корабль DD
        }
        else if (arr[x][y] == 'G') {
            arr[x][y] = 'O';
            return 3;   //для повторного удара в случае истины при попадании в двухпалубный корабль GG
        }
        else if (arr[x][y] == 'R') {
            arr[x][y] = 'O';
            return 4;   //для повторного удара в случае истины при попадании в двухпалубный корабль RR
        }
        else if (arr[x][y] == 'T') {
            arr[x][y] = 'O';
            return 5;   //для повторного удара в случае истины при попадании в треххпалубный корабль TTT
        }
        else {
            arr[x][y] = '*';
            return 0;
        }
    }
    //если булевая переменная истинная, то компьютер наносит удар по иным координатам вокруг раненого корабля
    //удар по двухпалубным кораблям
    else if (Ship_DD) {
        //Repeated_strike(arr, x, y, 'D');-не работает
      bool Cycle = false; //переменная для повтора цикла
        do {
            int Сoordinate = rand() % 4; //переменная для выбора дальнейшей координаты (компьютер пытается найти вторую палубы двухпалубного корабля RR)
            switch (Сoordinate) {
            case 0: { //верхняя ячейка
                if (x==0) Cycle = false; //проверка края игрового поля
                else {
                    if (arr[x - 1][y] == 'D') {
                        arr[x - 1][y] = 'O';
                        Cycle = true;
                        return 2;
                    }
                    else if (arr[x - 1][y] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x - 1][y] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 1: { //правая ячейка
                if (y == 9) Cycle = false;
                else {
                    if (arr[x][y + 1] == 'D') {
                        arr[x][y + 1] = 'O';
                        Cycle = true;
                        return 2;
                    }
                    else if (arr[x][y + 1] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x][y + 1] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 2: { //нижняя ячейка
                if (x == 9) Cycle = false;
                else {
                    if (arr[x + 1][y] == 'D') {
                        arr[x + 1][y] = 'O';
                        Cycle = true;
                        return 2;
                    }
                    else if (arr[x + 1][y] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x + 1][y] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 3: { //левая ячейка
                if (y == 0) Cycle = false;
                else {
                    if (arr[x][y - 1] == 'D') {
                        arr[x][y - 1] = 'O';
                        Cycle = true;
                        return 2;
                    }
                    else if (arr[x][y - 1] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x][y - 1] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            }
        } while (!Cycle);
    }
    else if (Ship_GG) {
        bool Cycle = false;
        do {
            int Сoordinate = rand() % 4; //переменная для выбора дальнейшей координаты (компьютер пытается найти вторую палубы двухпалубного корабля RR)
            switch (Сoordinate) {
            case 0: { //верхняя ячейка
                if (x == 0) Cycle = false; //проверка края игрового поля
                else {
                    if (arr[x - 1][y] == 'G') {
                        arr[x - 1][y] = 'O';
                        Cycle = true;
                        return 3;
                    }
                    else if (arr[x - 1][y] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x - 1][y] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 1: { //правая ячейка
                if (y == 9) Cycle = false;
                else {
                    if (arr[x][y + 1] == 'G') {
                        arr[x][y + 1] = 'O';
                        Cycle = true;
                        return 3;
                    }
                    else if (arr[x][y + 1] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x][y + 1] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 2: { //нижняя ячейка
                if (x == 9) Cycle = false;
                else {
                    if (arr[x + 1][y] == 'G') {
                        arr[x + 1][y] = 'O';
                        Cycle = true;
                        return 3;
                    }
                    else if (arr[x + 1][y] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x + 1][y] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 3: { //левая ячейка
                if (y == 0) Cycle = false;
                else {
                    if (arr[x][y - 1] == 'G') {
                        arr[x][y - 1] = 'O';
                        Cycle = true;
                        return 3;
                    }
                    else if (arr[x][y - 1] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x][y - 1] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            }
        } while (!Cycle);
    }
    else if (Ship_RR) {
        bool Cycle = false;
        do {
            int Сoordinate = rand() % 4; //переменная для выбора дальнейшей координаты (компьютер пытается найти вторую палубы двухпалубного корабля RR)
            switch (Сoordinate) {
            case 0: { //верхняя ячейка
                if (x == 0) Cycle = false; //проверка края игрового поля
                else {
                    if (arr[x - 1][y] == 'R') {
                        arr[x - 1][y] = 'O';
                        Cycle = true;
                        return 4;
                    }
                    else if (arr[x - 1][y] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x - 1][y] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 1: { //правая ячейка
                if (y == 9) Cycle = false;
                else {
                    if (arr[x][y + 1] == 'R') {
                        arr[x][y + 1] = 'O';
                        Cycle = true;
                        return 4;
                    }
                    else if (arr[x][y + 1] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x][y + 1] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 2: { //нижняя ячейка
                if (x == 9) Cycle = false;
                else {
                    if (arr[x + 1][y] == 'R') {
                        arr[x + 1][y] = 'O';
                        Cycle = true;
                        return 4;
                    }
                    else if (arr[x + 1][y] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x + 1][y] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 3: { //левая ячейка
                if (y == 0) Cycle = false;
                else {
                    if (arr[x][y - 1] == 'R') {
                        arr[x][y - 1] = 'O';
                        Cycle = true;
                        return 4;
                    }
                    else if (arr[x][y - 1] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x][y - 1] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            }
        } while (!Cycle);
    }
    ///////////////////////не работает корректно///////////////////
    else if (Ship_TTT) {
        if (Сoordinate_3_TTT==0)//если было только одно попадание в корабль ТТТ
        {
            bool Cycle = false;
            do {
                Сoordinate_3_TTT = 1 + rand() % 4; //переменная для выбора дальнейшей координаты (компьютер пытается найти вторую палубы трехпалубного корабля TTT)
                switch (Сoordinate_3_TTT) {
                case 1: { //верхняя ячейка
                    if (x == 0) Cycle = false; //проверка края игрового поля
                    else {
                        if (arr[x - 1][y] == 'T') {
                            arr[x - 1][y] = 'O';
                            Cycle = true;
                            return 5;
                        }
                        else if (arr[x - 1][y] == '*') {
                            Cycle = false;
                        }
                        else {
                            arr[x - 1][y] = '*';
                            Cycle = true;
                            Сoordinate_3_TTT = 0;
                            return 0;
                        };
                    }
                } break;
                case 2: { //правая ячейка
                    if (y == 9) Cycle = false;
                    else {
                        if (arr[x][y + 1] == 'T') {
                            arr[x][y + 1] = 'O';
                            Cycle = true;
                            return 5;
                        }
                        else if (arr[x][y + 1] == '*') {
                            Cycle = false;
                        }
                        else {
                            arr[x][y + 1] = '*';
                            Cycle = true;
                            Сoordinate_3_TTT = 0;
                            return 0;
                        };
                    }
                } break;
                case 3: { //нижняя ячейка
                    if (x == 9) Cycle = false;
                    else {
                        if (arr[x + 1][y] == 'T') {
                            arr[x + 1][y] = 'O';
                            Cycle = true;
                            return 5;
                        }
                        else if (arr[x + 1][y] == '*') {
                            Cycle = false;
                        }
                        else {
                            arr[x + 1][y] = '*';
                            Cycle = true;
                            Сoordinate_3_TTT = 0;
                            return 0;
                        };
                    }
                } break;
                case 4: { //левая ячейка
                    if (y == 0) Cycle = false;
                    else {
                        if (arr[x][y - 1] == 'T') {
                            arr[x][y - 1] = 'O';
                            Cycle = true;
                            return 4;
                        }
                        else if (arr[x][y - 1] == '*') {
                            Cycle = false;
                        }
                        else {
                            arr[x][y - 1] = '*';
                            Cycle = true;
                            Сoordinate_3_TTT = 0;
                            return 0;
                        };
                    }
                } break;
                }
            } while (!Cycle);
        }
        else if (Сoordinate_3_TTT == 1) //верхняя ячейка
        {
            bool Cycle = false;
            do {
                int Сoordinate_3_2_TTT = rand() % 2; //компьютер угадывает координату либо сверху либо снизу
                switch (Сoordinate_3_2_TTT) {
                case 0: {
                    if (x == 1) Cycle = false; //проверка края игрового поля
                    else {  //угадывание палубы сверху
                        if (arr[x - 2][y] == 'T') {
                            arr[x - 2][y] = 'O';
                            Cycle = true;
                            return 5;
                        }
                        else if (arr[x - 2][y] == '*') {
                            Cycle = false;
                        }
                        else {
                            arr[x - 2][y] = '*';
                            Cycle = true;
                            return 0;
                        };
                    }
                } break;
                case 1: {
                    if (x == 9) Cycle = false; //проверка края игрового поля
                    else {  //угадывание палубы снизу
                        if (arr[x + 1][y] == 'T') {
                            arr[x + 1][y] = 'O';
                            Cycle = true;
                            return 5;
                        }
                        else if (arr[x + 1][y] == '*') {
                            Cycle = false;
                        }
                        else {
                            arr[x + 1][y] = '*';
                            Cycle = true;
                            return 0;
                        };
                    }
                } break;
                }
            } while (Cycle);
        }
        else if (Сoordinate_3_TTT == 2)//правая ячейка
        {
        bool Cycle = false;
        do {
            int Сoordinate_3_2_TTT = rand() % 2; //компьютер угадывает координату либо справа либо слева
            switch (Сoordinate_3_2_TTT) {
            case 0: {
                if (y == 8) Cycle = false; //проверка края игрового поля
                else {  //угадывание палубы справа
                    if (arr[x][y + 2] == 'T') {
                        arr[x][y + 2] = 'O';
                        Cycle = true;
                        return 5;
                    }
                    else if (arr[x][y + 2] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x][y + 2] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 1: {
                if (y == 0) Cycle = false; //проверка края игрового поля
                else {  //угадывание палубы слева
                    if (arr[x][y - 1] == 'T') {
                        arr[x][y - 1] = 'O';
                        Cycle = true;
                        return 5;
                    }
                    else if (arr[x][y - 1] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x][y - 1] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            }
        } while (Cycle);
        }
        else if (Сoordinate_3_TTT == 3)//нижняя ячейка
        {
        bool Cycle = false;
        do {
            int Сoordinate_3_2_TTT = rand() % 2; //компьютер угадывает координату либо справа либо слева
            switch (Сoordinate_3_2_TTT) {
            case 0: {
                if (x == 8) Cycle = false; //проверка края игрового поля
                else {  //угадывание палубы снизу
                    if (arr[x+2][y] == 'T') {
                        arr[x + 2][y] = 'O';
                        Cycle = true;
                        return 5;
                    }
                    else if (arr[x + 2][y] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x + 2][y] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 1: {
                if (x == 0) Cycle = false; //проверка края игрового поля
                else {  //угадывание палубы сверху
                    if (arr[x-1][y] == 'T') {
                        arr[x - 1][y] = 'O';
                        Cycle = true;
                        return 5;
                    }
                    else if (arr[x - 1][y] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x - 1][y] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            }
        } while (Cycle);
        }
        else if (Сoordinate_3_TTT == 4)//левая ячейка
        {
        bool Cycle = false;
        do {
            int Сoordinate_3_2_TTT = rand() % 2; //компьютер угадывает координату либо справа либо слева
            switch (Сoordinate_3_2_TTT) {
            case 0: {
                if (y == 1) Cycle = false; //проверка края игрового поля
                else {  //угадывание палубы слева
                    if (arr[x][y - 1] == 'T') {
                        arr[x][y - 1] = 'O';
                        Cycle = true;
                        return 5;
                    }
                    else if (arr[x][y - 1] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x][y - 1] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 1: {
                if (y == 9) Cycle = false; //проверка края игрового поля
                else {  //угадывание палубы справа
                    if (arr[x][y + 1] == 'T') {
                        arr[x][y + 1] = 'O';
                        Cycle = true;
                        return 5;
                    }
                    else if (arr[x][y + 1] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x][y + 1] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            }
        } while (Cycle);
        }

    }
}


