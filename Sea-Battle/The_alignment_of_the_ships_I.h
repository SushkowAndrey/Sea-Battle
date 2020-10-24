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
// внутренний цикл проверки расстановки кораблей - строка У, наружний - столбец Х

// описание функции игрока
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
                cout << "Укажите координату однопалубного корабля (столбец) "; 
                cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e'
                && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите координату однопалубного корабля (строка) ";
            x= Proverka_vvoda(Game_Step, 3);
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей
        //проверка свободных ячeeк вокруг координаты
        Result_vybora = Check_the_ships_around(arr, x, y);
    } while (!Result_vybora);
    arr[x][y] = 'K';
}
//функция расстановки двухпалубных кораблей первого игрока
//первый двухпалубный корабль
//первая палуба
void Rasstanovka_kor_2_pal_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora1, Result_vybora2, Result_vybora3, Result_vybora4;
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora1 = true, Result_vybora2 = true, Result_vybora3 = true, Result_vybora4 = true;
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
        //проверка свободных ячeeк вокруг координаты
        Result_vybora1= Checking_cells_2_up(arr, x, y);
        Result_vybora2 = Checking_cells_2_right(arr, x, y);
        Result_vybora3 = Checking_cells_2_down(arr, x, y);
        Result_vybora4 = Checking_cells_2_left(arr, x, y);
    } while (!Result_vybora1 && !Result_vybora2 && !Result_vybora3 && !Result_vybora4);
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
        Result_vybora = Check_the_ships_around(arr, x, y);
        //проверка наличия рядом первой палубы двухпалубного корабля перпендикулярно
        if (Result_vybora) { 
            //данная проверка нужня для того, что бы ячейки не перескакивали с одного края поля на другой
            //если у нас х=0, то у можно поставить на другом краю поля, поэтому нужно исключить проверку поля слева, если у=9
            Result_vybora= The_choice_of_the_second_deck(x, y, arr, 'D');
        }
    } while (!Result_vybora);
    arr[x][y] = 'D';
}
//второй двухпалубный корабль игрока
//первая палуба
void Rasstanovka_kor_2_2_pal_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora1, Result_vybora2, Result_vybora3, Result_vybora4;
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora1 = true, Result_vybora2 = true, Result_vybora3 = true, Result_vybora4 = true;
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
        Result_vybora1 = Checking_cells_2_up(arr, x, y);
        Result_vybora2 = Checking_cells_2_right(arr, x, y);
        Result_vybora3 = Checking_cells_2_down(arr, x, y);
        Result_vybora4 = Checking_cells_2_left(arr, x, y);
    } while (!Result_vybora1 && !Result_vybora2 && !Result_vybora3 && !Result_vybora4);
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
        Result_vybora = Check_the_ships_around(arr, x, y, 'D');
        //проверка наличия рядом первой палубы двухпалубного корабля, который мы ставим
        if (Result_vybora) {
            //данная проверка нужня для того, что бы ячейки не перескакивали с одного края поля на другой
            //если у нас х=0, то у можно поставить на другом краю поля, поэтому нужно исключить проверку поля слева, если у=9
            Result_vybora = The_choice_of_the_second_deck(x, y, arr, 'G');
        }
    } while (!Result_vybora);
    arr[x][y] = 'G';
}

//третий двухпалубный корабль игрока
//первая палуба
void Rasstanovka_kor_2_3_pal_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora1, Result_vybora2, Result_vybora3, Result_vybora4;
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    do {
        Result_vybora1 = true, Result_vybora2 = true, Result_vybora3 = true, Result_vybora4 = true;
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
        Result_vybora1 = Checking_cells_2_up(arr, x, y);
        Result_vybora2 = Checking_cells_2_right(arr, x, y);
        Result_vybora3 = Checking_cells_2_down(arr, x, y);
        Result_vybora4 = Checking_cells_2_left(arr, x, y);
    } while (!Result_vybora1 && !Result_vybora2 && !Result_vybora3 && !Result_vybora4);
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
        //и есть рядом палуба корабля
        Result_vybora = Check_the_ships_around(arr, x, y, 'D', 'G');
        //проверка наличия рядом первой палубы двухпалубного корабля R
        if (Result_vybora) {
            //данная проверка нужня для того, что бы ячейки не перескакивали с одного края поля на другой
            //если у нас х=0, то у можно поставить на другом краю поля, поэтому нужно исключить проверку поля слева, если у=9
            Result_vybora = The_choice_of_the_second_deck(x, y, arr, 'R');
        }
    } while (!Result_vybora);
    arr[x][y] = 'R';
}


/////////////////////////////////////////////////////////////////////////
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


