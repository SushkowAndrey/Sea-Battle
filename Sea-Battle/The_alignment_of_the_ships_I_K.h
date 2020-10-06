#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "Other_Fun.h"

using namespace std;

/*палубы кораблей боя игрока и компьютера - обозначения
К-однопалубный корабль
DD-первый двухпалубный корабль
GG-второй двухпалубный корабль
RR-третий двухпалубный корабль
TTT-первый трехпалубный корабль*/
// внутренний цикл проверки расстановки кораблей - сторока У, наружний - столбец Х

// описание функции игрока и компьютера
//функция расстановки однопалубных кораблей первого игрока
void Rasstanovka_kor(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату однопалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e'
                && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            //cout << "Укажите координату однопалубного корабля (столбец) ";
            //St= Proverka_vvoda(Game_Step, 4);
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату однопалубного корабля (строка) ";
            x= Proverka_vvoda(Game_Step, 3);
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
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату первого двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату первого двухпалубного корабля (строка) ";
            x = Proverka_vvoda(Game_Step, 3);
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
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату первого двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату первого двухпалубного корабля (строка) ";
            x = Proverka_vvoda(Game_Step, 3);
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
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату второго двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату второго двухпалубного корабля (строка) ";
            x = Proverka_vvoda(Game_Step, 3);
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
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату второго двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату второго двухпалубного корабля (строка) ";
            x = Proverka_vvoda(Game_Step, 3);
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
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату третьего двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату третьего двухпалубного корабля (строка) ";
            x = Proverka_vvoda(Game_Step, 3);
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
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите координату второго двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату второго двухпалубного корабля (строка) ";
            x = Proverka_vvoda(Game_Step, 3);
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

//функция расстановки трехпалубных кораблей первого игрока
//первый трехпалубный корабль
//первая палуба
void Rasstanovka_kor_3_pal_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora_1, Result_vybora_2, Result_vybora_3, Result_vybora_4;
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora_1 = true, Result_vybora_2=true, Result_vybora_3 = true, Result_vybora_4 = true;
        do {
            do {
                cout << "Укажите координату первого трехпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату первого трехпалубного корабля (строка) ";
            x = Proverka_vvoda(Game_Step, 3);
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей
        //проверка свободных ячeeк вокруг координаты
        for (int i = -1; i < 4; i++) { //проверка координат вниз
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_1 = false;
                    break;
                }
            }
            if (!Result_vybora_1)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат вправо
            for (int j = -1; j < 4; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_2 = false;
                    break;
                }
            }
            if (!Result_vybora_2)
                break;
        }
        for (int i = -3; i < 2; i++) {//проверка координат вверх
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_3 = false;
                    break;
                }
            }
            if (!Result_vybora_3)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат влево
            for (int j = -3; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_4 = false;
                    break;
                }
            }
            if (!Result_vybora_4)
                break;
        }
    } while (!Result_vybora_1 && !Result_vybora_2 && !Result_vybora_3 && !Result_vybora_4);
    arr[x][y] = 'T';
}
//вторая палуба
void Rasstanovka_kor_3_pal_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora_1, Result_vybora_2, Result_vybora_3, Result_vybora_4;
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora_1 = true, Result_vybora_2 = true, Result_vybora_3 = true, Result_vybora_4 = true;
        do {
            do {
                cout << "Укажите координату первого трехпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату первого трехпалубного корабля (строка) ";
            x = Proverka_vvoda(Game_Step, 3);
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей 
        //и есть рядом палуба  корабля
        for (int i = -2; i < 3; i++) { //проверка координат вниз (на 1 размер ячейки меньше, тк одна палуба уже имеется и по ней все проверено)
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_1 = false;
                    break;
                }
            }
            if (!Result_vybora_1)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат вправо
            for (int j = -2; j < 3; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_2 = false;
                    break;
                }
            }
            if (!Result_vybora_2)
                break;
        }
        for (int i = -2; i < 3; i++) {//проверка координат вверх
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_3 = false;
                    break;
                }
            }
            if (!Result_vybora_3)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат влево
            for (int j = -2; j < 3; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_4 = false;
                    break;
                }
            }
            if (!Result_vybora_4)
                break;
        }
        //проверка наличия рядом первой палубы треххпалубного корабля
        if (Result_vybora_1) { //проверяет есть ли первая палуба над выбранной координатой
            if (arr[x - 1][y] == 'T') Result_vybora_1 = true;
            else Result_vybora_1 = false;
        }
        if (Result_vybora_2) { //проверяет есть ли первая палуба слева выбранной координатой
            if (arr[x][y-1] == 'T') Result_vybora_2 = true;
            else Result_vybora_2 = false;
        }
        if (Result_vybora_3) { //проверяет есть ли первая палуба под выбранной координатой
            if (arr[x+1][y] == 'T') Result_vybora_3 = true;
            else Result_vybora_3 = false;
        }
        if (Result_vybora_4) { //проверяет есть ли первая палуба слева выбранной координатой
            if (arr[x][y+1] == 'T') Result_vybora_4 = true;
            else Result_vybora_4 = false;
        }
    } while (!Result_vybora_1 && !Result_vybora_2 && !Result_vybora_3 && !Result_vybora_4);
    arr[x][y] = 'T';
}

//третья палуба
void Rasstanovka_kor_3_pal_3(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora_1, Result_vybora_2, Result_vybora_3, Result_vybora_4;
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora_1 = true, Result_vybora_2 = true, Result_vybora_3 = true, Result_vybora_4 = true;
        do {
            do {
                cout << "Укажите координату первого трехпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату первого трехпалубного корабля (строка) ";
            x = Proverka_vvoda(Game_Step, 3);
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей 
        //и есть рядом палуба  корабля
        for (int i = -1; i < 2; i++) { //проверка координат вниз (еще на 1 размер ячейки меньше, тк две палубы уже имеется и по ней все проверено)
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_1 = false;
                    break;
                }
            }
            if (!Result_vybora_1)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат вправо
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_2 = false;
                    break;
                }
            }
            if (!Result_vybora_2)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат вверх
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_3 = false;
                    break;
                }
            }
            if (!Result_vybora_3)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат влево
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_4 = false;
                    break;
                }
            }
            if (!Result_vybora_4)
                break;
        }
        //проверка наличия рядом первой палубы треххпалубного корабля
        if (Result_vybora_1) { //проверяет есть ли первая и вторая палуба над выбранной координатой
            if (arr[x - 1][y] == 'T'&& arr[x-2][y] == 'T') Result_vybora_1 = true;
            else Result_vybora_1 = false;
        }
        if (Result_vybora_2) { //проверяет есть ли первая и вторая палуба слева выбранной координатой
            if (arr[x][y - 1] == 'T' && arr[x][y-2] == 'T') Result_vybora_2 = true;
            else Result_vybora_2 = false;
        }
        if (Result_vybora_3) { //проверяет есть ли первая и вторая палуба под выбранной координатой
            if (arr[x + 1][y] == 'T' && arr[x+2][y] == 'T') Result_vybora_3 = true;
            else Result_vybora_3 = false;
        }
        if (Result_vybora_4) { //проверяет есть ли первая и вторая палуба слева выбранной координатой
            if (arr[x][y + 1] == 'T' && arr[x][y + 2] == 'T') Result_vybora_4 = true;
            else Result_vybora_4 = false;
        }
    } while (!Result_vybora_1 && !Result_vybora_2 && !Result_vybora_3 && !Result_vybora_4);
    arr[x][y] = 'T';
}



////////////////////////РАССТАНОВКА КОРАБЛЕЙ КОМПЬЮТЕРОМ///////////////////////////////
//функция расстановки однопалубных кораблей компьютера
void Rasstanovka_kor_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora = false;
    do {
        Result_vybora = true;
        do {
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
        } while (y < 0 || y > 9);
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
    //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей
    //проверка свободных ячeeк вокруг координаты
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
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
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
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
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
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
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
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
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
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
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
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
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

//функция расстановки трехпалубных кораблей компьютером
//первый трехпалубный корабль
//первая палуба
void Rasstanovka_kor_3_pal_1_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora_1, Result_vybora_2, Result_vybora_3, Result_vybora_4;
    do {
        Result_vybora_1 = true, Result_vybora_2 = true, Result_vybora_3 = true, Result_vybora_4 = true;
        do {
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
        } while (y < 0 || y > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей
        //проверка свободных ячeeк вокруг координаты
        for (int i = -1; i < 4; i++) { //проверка координат вниз
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_1 = false;
                    break;
                }
            }
            if (!Result_vybora_1)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат вправо
            for (int j = -1; j < 4; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_2 = false;
                    break;
                }
            }
            if (!Result_vybora_2)
                break;
        }
        for (int i = -3; i < 2; i++) {//проверка координат вверх
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_3 = false;
                    break;
                }
            }
            if (!Result_vybora_3)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат влево
            for (int j = -3; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_4 = false;
                    break;
                }
            }
            if (!Result_vybora_4)
                break;
        }
    } while (!Result_vybora_1 && !Result_vybora_2 && !Result_vybora_3 && !Result_vybora_4);
    arr[x][y] = 'T';
}
//вторая палуба
void Rasstanovka_kor_3_pal_2_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora_1, Result_vybora_2, Result_vybora_3, Result_vybora_4;
    do {
        Result_vybora_1 = true, Result_vybora_2 = true, Result_vybora_3 = true, Result_vybora_4 = true;
        do {
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
        } while (y < 0 || y > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей 
        //и есть рядом палуба  корабля
        for (int i = -2; i < 3; i++) { //проверка координат вниз (на 1 размер ячейки меньше, тк одна палуба уже имеется и по ней все проверено)
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_1 = false;
                    break;
                }
            }
            if (!Result_vybora_1)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат вправо
            for (int j = -2; j < 3; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_2 = false;
                    break;
                }
            }
            if (!Result_vybora_2)
                break;
        }
        for (int i = -2; i < 3; i++) {//проверка координат вверх
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_3 = false;
                    break;
                }
            }
            if (!Result_vybora_3)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат влево
            for (int j = -2; j < 3; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_4 = false;
                    break;
                }
            }
            if (!Result_vybora_4)
                break;
        }
        //проверка наличия рядом первой палубы треххпалубного корабля
        if (Result_vybora_1) { //проверяет есть ли первая палуба над выбранной координатой
            if (arr[x - 1][y] == 'T') Result_vybora_1 = true;
            else Result_vybora_1 = false;
        }
        if (Result_vybora_2) { //проверяет есть ли первая палуба слева выбранной координатой
            if (arr[x][y - 1] == 'T') Result_vybora_2 = true;
            else Result_vybora_2 = false;
        }
        if (Result_vybora_3) { //проверяет есть ли первая палуба под выбранной координатой
            if (arr[x + 1][y] == 'T') Result_vybora_3 = true;
            else Result_vybora_3 = false;
        }
        if (Result_vybora_4) { //проверяет есть ли первая палуба слева выбранной координатой
            if (arr[x][y + 1] == 'T') Result_vybora_4 = true;
            else Result_vybora_4 = false;
        }
    } while (!Result_vybora_1 && !Result_vybora_2 && !Result_vybora_3 && !Result_vybora_4);
    arr[x][y] = 'T';
}

//третья палуба
void Rasstanovka_kor_3_pal_3_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora_1, Result_vybora_2, Result_vybora_3, Result_vybora_4;
    do {
        Result_vybora_1 = true, Result_vybora_2 = true, Result_vybora_3 = true, Result_vybora_4 = true;
        do {
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
        } while (y < 0 || y > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей 
        //и есть рядом палуба  корабля
        for (int i = -1; i < 2; i++) { //проверка координат вниз (еще на 1 размер ячейки меньше, тк две палубы уже имеется и по ней все проверено)
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_1 = false;
                    break;
                }
            }
            if (!Result_vybora_1)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат вправо
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_2 = false;
                    break;
                }
            }
            if (!Result_vybora_2)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат вверх
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_3 = false;
                    break;
                }
            }
            if (!Result_vybora_3)
                break;
        }
        for (int i = -1; i < 2; i++) {//проверка координат влево
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_4 = false;
                    break;
                }
            }
            if (!Result_vybora_4)
                break;
        }
        //проверка наличия рядом первой палубы треххпалубного корабля
        if (Result_vybora_1) { //проверяет есть ли первая и вторая палуба над выбранной координатой
            if (arr[x - 1][y] == 'T' && arr[x - 2][y] == 'T') Result_vybora_1 = true;
            else Result_vybora_1 = false;
        }
        if (Result_vybora_2) { //проверяет есть ли первая и вторая палуба слева выбранной координатой
            if (arr[x][y - 1] == 'T' && arr[x][y - 2] == 'T') Result_vybora_2 = true;
            else Result_vybora_2 = false;
        }
        if (Result_vybora_3) { //проверяет есть ли первая и вторая палуба под выбранной координатой
            if (arr[x + 1][y] == 'T' && arr[x + 2][y] == 'T') Result_vybora_3 = true;
            else Result_vybora_3 = false;
        }
        if (Result_vybora_4) { //проверяет есть ли первая и вторая палуба слева выбранной координатой
            if (arr[x][y + 1] == 'T' && arr[x][y + 2] == 'T') Result_vybora_4 = true;
            else Result_vybora_4 = false;
        }
    } while (!Result_vybora_1 && !Result_vybora_2 && !Result_vybora_3 && !Result_vybora_4);
    arr[x][y] = 'T';
}
