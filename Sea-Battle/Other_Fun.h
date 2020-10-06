#pragma once
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int SIZE = 10;

// описание функции
//функция замены буквенного значения координаты столбца на цифру
int Zamena_B_na_Num(char Koord) {
    int y = 0;
    if (Koord == 'a') {
        y = 0;
    }
    else if (Koord == 'b') {
        y = 1;
    }
    else if (Koord == 'c') {
        y = 2;
    }
    else if (Koord == 'd') {
        y = 3;
    }
    else if (Koord == 'e') {
        y = 4;
    }
    else if (Koord == 'f') {
        y = 5;
    }
    else if (Koord == 'g') {
        y = 6;
    }
    else if (Koord == 'h') {
        y = 7;
    }
    else if (Koord == 'i') {
        y = 8;
    }
    else if (Koord == 'j') {
        y = 9;
    }
    return y;
}
// функция горизонтальной границы координат
void Gor_Granica(char* arr, int size) {
    for (int i = 0; i < (SIZE + 1); i++) {  //верхняя граница координат
        cout << "|" << *(arr + i) << "|";
    }
}

//функция показа кораблей
void Pokaz_Ship(char arr[SIZE][SIZE]) {
    for (int x = 0; x < 10; x++) {
        cout << "|" << x << "|";
        for (int y = 0; y < 10; y++) {
            cout << "|" << arr[x][y] << "|";
        }
        cout << endl;
    }
}

//функция подсчета количества подбитых кораблей
int Result(char arr[SIZE][SIZE]) {
    int count = 0;
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (arr[x][y] == 'O')
                count++;
        }
        cout << endl;
    }
    return count;
}

//функция для проверки на дурака
int Proverka_vvoda(string Sym, int Menu) {
    int Num = 0; //переменная для проверки на правильность ввода данных, опреденяет номер символа по таблице ASCII
    //проверка на дурака в главном меню
    if (Menu == 0) {
        while (Sym.size() != 1 || (Num != 49 && Num != 50 && Num != 51))
        {
            cin >> Sym;
            for (int i = 0; i < Sym.size(); i++)
            {
                Num = Sym[i];
            }
            if (Sym.size() != 1 || (Num != 49 && Num != 50 && Num != 51)) {
                cout << "Некорректное значение главного меню при выборе 1, 2, 3, повторите ввод " << endl;
            }
        }
        int Result = Sym[0] - '0'; //переменная, в которую преобразуется строка для определения типа игры
        return Result;
    }
    //проверка на дурака в конце игры
    else if (Menu == 1) {
        while (Sym.size() != 1 || (Num != 78 && Num != 89))
        {
            cin >> Sym;
            for (int i = 0; i < Sym.size(); i++)
            {
                Num = Sym[i];
            }
            if (Sym.size() != 1 || (Num != 78 && Num != 89)) {
                cout << "Некорректное значение в конце игры при выборе Y/N, повторите ввод " << endl;
            }
        }
        char Result = Sym[0]; //переменная, в которую преобразуется строка для определения типа игры
        return Result;
    }
    //проверка на дурака при нажатии на 0
    else if (Menu == 2) {
        while (Sym.size() != 1 || Num != 48)
        {
            cin >> Sym;
            for (int i = 0; i < Sym.size(); i++)
            {
                Num = Sym[i];
            }
            if (Sym.size() != 1 || Num != 48) {
                cout << "Некорректное значение при нажатии на 0, повторите ввод " << endl;
            }
        }
        int Result = Sym[0] - '0'; //переменная, в которую преобразуется строка для определения типа игры
        return Result;
    }
    //проверка на дурака при выборе координат цифр
    else if (Menu == 3) {
        while (Sym.size() != 1 || (Num < 49 && Num > 57))
        {
            cin >> Sym;
            for (int i = 0; i < Sym.size(); i++)
            {
                Num = Sym[i];
            }
            if (Sym.size() != 1 || (Num < 49 && Num > 57)) {
                cout << "Некорректное значение при выборе координат от 1 до 10, повторите ввод " << endl;
            }
        }
        int Result = Sym[0] - '0'; //переменная, в которую преобразуется строка для определения типа игры
        return Result;
    }
    //проверка на дурака при выборе координат букв
    else if (Menu == 4) {
        while (Sym.size() != 1 || (Num < 97 && Num > 106))
        {
            cin >> Sym;
            for (int i = 0; i < Sym.size(); i++)
            {
                Num = Sym[i];
            }
            if (Sym.size() != 1 || (Num < 97 && Num > 106)) {
                cout << "Некорректное значение при выборе координат от a до j, повторите ввод " << endl;
            }
        }
        char Result = Sym[0]; //переменная, в которую преобразуется строка для определения типа игры
        return Result;
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

//функция отображения результатов хода двух игроков (подбитые корабли и промахи первого и второго игрока)
void Pokaz_Udar_2(char arr1[SIZE][SIZE], char arr2[SIZE][SIZE]) {
    for (int x = 0; x < 10; x++) {
        cout << "|" << x << "|";    //обозначение столбца координат по циклу
        for (int y = 0; y < 10; y++) {
            if (arr1[x][y] == 'O' || arr1[x][y] == '*') {
                cout << "|" << arr1[x][y] << "|";
            }
            else {
                cout << "| |";
            }
        }
        cout << "     ";
        cout << "|" << x << "|";//обозначение столбца координат по циклу
        for (int y = 0; y < 10; y++) {
            if (arr2[x][y] == 'O' || arr2[x][y] == '*') {
                cout << "|" << arr2[x][y] << "|";
            }
            else {
                cout << "| |";
            }
        }
        cout << endl;
    }
}
/////////не работает
/*
//функция повторного удара компьютера по раненому двухпалубному кораблю
int Repeated_strike(char arr[SIZE][SIZE], int x, int y, char Sym_Ship) {
    bool Cycle = false; //переменная для повтора цикла
    do {
            int Сoordinate = rand() % 4; //переменная для выбора дальнейшей координаты (компьютер пытается найти вторую палубы двухпалубного корабля RR)
            switch (Сoordinate) {
            case 0: { //верхняя ячейка
                if (x==0) Cycle = false; //проверка края игрового поля
                else {
                    if (arr[x - 1][y] == Sym_Ship) {
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
                    if (arr[x][y + 1] == Sym_Ship) {
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
                    if (arr[x + 1][y] == Sym_Ship) {
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
                    if (arr[x][y - 1] == Sym_Ship) {
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
*/