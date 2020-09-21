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
            system("cls");
            cout << "Некорректное значение, повторите ввод " << endl;
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
            system("cls");
            cout << "Некорректное значение, повторите ввод " << endl;
        }
        char Result = Sym[0]; //переменная, в которую преобразуется строка для определения типа игры
        return Result;
    }
}