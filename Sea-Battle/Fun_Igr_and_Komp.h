#pragma once
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

/*палубы кораблей боя игрока и компьютера - обозначения
К-однопалубный корабль
DD-первый двухпалубный корабль
GG-второй двухпалубный корабль
RR-третий двухпалубный корабль*/

// описание функции игрока и компьютера
//функция расстановки однопалубных кораблей первого игрока
void Rasstanovka_kor(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату однопалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e'
                && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату однопалубного корабля (строка) "; cin >> x;
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей
        //проверка свободных ячeeк вокруг координаты
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'K') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
    } while (!Result_vybora);
    arr[x][y] = 'K';
}
//функция расстановки двухпалубных кораблей первого игрока
//первый двухпалубный корабль
//первая палуба
void Rasstanovka_kor_2_pal_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату первого двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату первого двухпалубного корабля (строка) "; cin >> x;
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей
        //проверка свободных ячeeк вокруг координаты
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
    } while (!Result_vybora);
    arr[x][y] = 'D';
}
//вторая палуба
void Rasstanovka_kor_2_pal_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату первого двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату первого двухпалубного корабля (строка) "; cin >> x;
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей 
        //и есть рядом палуба корабля
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
        //проверка наличия рядом первой палубы двухпалубного корабля перпендикулярно
        if (Result_vybora) {
            if (arr[x - 1][y] == 'D' || arr[x + 1][y] == 'D' || arr[x][y - 1] == 'D' || arr[x][y + 1] == 'D')
                break;
            else
                Result_vybora = false;
        }
    } while (!Result_vybora);

    arr[x][y] = 'D';
}
//второй двухпалубный корабль игрока
//первая палуба
void Rasstanovka_kor_2_2_pal_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату второго двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату второго двухпалубного корабля (строка) "; cin >> x;
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей
        //проверка свободных ячeeк вокруг координаты
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'K') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
    } while (!Result_vybora);
    arr[x][y] = 'G';
}
//вторая палуба
void Rasstanovka_kor_2_2_pal_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату второго двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату второго двухпалубного корабля (строка) "; cin >> x;
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей 
        //и есть рядом палуба другого корабля
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K'|| arr[x + i][y + j] == 'D') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
        //проверка наличия рядом первой палубы двухпалубного корабля, который мы ставим
        if (Result_vybora) {
            if (arr[x - 1][y] == 'G' || arr[x + 1][y] == 'G' || arr[x][y - 1] == 'G' || arr[x][y + 1] == 'G')
                break;
            else
                Result_vybora = false;
        }
    } while (!Result_vybora);

    arr[x][y] = 'G';
}

//третий двухпалубный корабль игрока
//первая палуба
void Rasstanovka_kor_2_3_pal_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату третьего двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату третьего двухпалубного корабля (строка) "; cin >> x;
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей
        //проверка свободных ячeeк вокруг координаты
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'G') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
    } while (!Result_vybora);
    arr[x][y] = 'R';
}
//вторая палуба
void Rasstanovka_kor_2_3_pal_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату второго двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату второго двухпалубного корабля (строка) "; cin >> x;
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей 
        //и есть рядом палуба  корабля
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
        //проверка наличия рядом первой палубы двухпалубного корабля
        if (Result_vybora) {
            if (arr[x - 1][y] == 'R' || arr[x + 1][y] == 'R' || arr[x][y - 1] == 'R' || arr[x][y + 1] == 'R')
                break;
            else
                Result_vybora = false;
        }
    } while (!Result_vybora);

    arr[x][y] = 'R';
}


////////////////////////РАССТАНОВКА КОРАБЛЕЙ КОМПЬЮТЕРОМ///////////////////////////////
//функция расстановки однопалубных кораблей компьютера
void Rasstanovka_kor_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    do {
        do {
            x = rand() % 9;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 9;
        } while (y < 0 || y > 9);

    } while (arr[x][y] == 'K');
    arr[x][y] = 'K';
}

//функция расстановки двухпалубных кораблей компьютером
//первый двухпалубный корабль
//первая палуба
void Rasstanovka_kor_2_pal_1_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            x = rand() % 9;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 9;
        } while (y < 0 || y > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей
        //проверка свободных ячeeк вокруг координаты
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
    } while (!Result_vybora);
    arr[x][y] = 'D';
}
//вторая палуба
void Rasstanovka_kor_2_pal_2_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            x = rand() % 9;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 9;
        } while (y < 0 || y > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей 
        //и есть рядом палуба корабля
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
        //проверка наличия рядом первой палубы двухпалубного корабля
        if (Result_vybora) {
            if (arr[x - 1][y] == 'D' || arr[x + 1][y] == 'D' || arr[x][y - 1] == 'D' || arr[x][y + 1] == 'D')
                break;
            else
                Result_vybora = false;
        }
    } while (!Result_vybora);

    arr[x][y] = 'D';
}
//второй двухпалубный корабль
//первая палуба
void Rasstanovka_kor_2_2_pal_1_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            x = rand() % 9;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 9;
        } while (y < 0 || y > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей
        //проверка свободных ячeeк вокруг координаты
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K'|| arr[x + i][y + j] == 'D') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
    } while (!Result_vybora);
    arr[x][y] = 'G';
}
//вторая палуба
void Rasstanovka_kor_2_2_pal_2_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            x = rand() % 9;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 9;
        } while (y < 0 || y > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей 
        //и есть рядом палубакорабля
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
        //проверка наличия рядом первой палубы двухпалубного корабля
        if (Result_vybora) {
            if (arr[x - 1][y] == 'G' || arr[x + 1][y] == 'G' || arr[x][y - 1] == 'G' || arr[x][y + 1] == 'G')
                break;
            else
                Result_vybora = false;
        }
    } while (!Result_vybora);

    arr[x][y] = 'G';
}
//второй двухпалубный корабль
//первая палуба
void Rasstanovka_kor_2_3_pal_1_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            x = rand() % 9;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 9;
        } while (y < 0 || y > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей
        //проверка свободных ячeeк вокруг координаты
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
    } while (!Result_vybora);
    arr[x][y] = 'R';
}
//вторая палуба
void Rasstanovka_kor_2_3_pal_2_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            x = rand() % 9;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 9;
        } while (y < 0 || y > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей 
        //и есть рядом палубакорабля
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G') {
                    Result_vybora = false;
                    break;
                }
            }
            if (!Result_vybora)
                break;
        }
        //проверка наличия рядом первой палубы двухпалубного корабля
        if (Result_vybora) {
            if (arr[x - 1][y] == 'R' || arr[x + 1][y] == 'R' || arr[x][y - 1] == 'R' || arr[x][y + 1] == 'R')
                break;
            else
                Result_vybora = false;
        }
    } while (!Result_vybora);

    arr[x][y] = 'R';
}

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
        return 1;   //для повторного удара в случае истины при попадании в однопалубный корабль
    }
    else if (arr[x][y] == 'D') {
        arr[x][y] = 'O';
        return 2;   //для повторного удара в случае истины при попадании в двухпалубный корабль
    }
    else {
        arr[x][y] = '*';
        return 0;
    }
}


//функция хода компьютера
int HodKomp(char arr[SIZE][SIZE])
{
    int x, y;
    do {
        do {
            x = rand() % 9;               //строка
        } while (x < 0 || x > 9);
        do {
            y = rand() % 9;              //столбец
        } while (y < 0 || y > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
        return 1;   //для повторного удара в случае истины при попадании в однопалубный корабль
    }
    else if (arr[x][y] == 'D') {
        arr[x][y] = 'O';
        return 2;   //для повторного удара в случае истины при попадании в двухпалубный корабль
    }
    else {
        arr[x][y] = '*';
        return 0;
    }
}

//функция отображения результатов хода (подбитые корабли и промахи игрока и компьютера)
void Pokaz_Udar(char arr1[SIZE][SIZE], char arr2[SIZE][SIZE]) {
    for (int x = 0; x < 10; x++) {
        cout << "|" << x << "|";
        for (int y = 0; y < 10; y++) {
            cout << "|" << arr2[x][y] << "|";
        }
        cout << "     ";
        cout << "|" << x << "|";
        for (int y = 0; y < 10; y++) {
            if (arr1[x][y] == 'O' || arr1[x][y] == '*') {
                cout << "|" << arr1[x][y] << "|";
            }
            else {
                cout << "| |";
            }
        }
        cout << endl;
    }
}
