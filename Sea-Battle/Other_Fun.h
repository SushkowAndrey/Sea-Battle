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
inline void Gor_Granica(char* arr, int size) {
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

//функция для проверки на дурака другая
int Checking_the_symbol(string M)
{
    if (M.size() != 1) return 10;
    else {
        int Num;
        for (int i = 0; i < M.size(); i++)
        {
            Num = M[i];
        }
        if (Num > 47 && Num < 56) {
            return Num - '0';
        }
        else return 10;
    }
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
//очистка поля при автоматическом заполнении игрового поля
void The_clearing_of_a_field(char arr[SIZE][SIZE]) {
    for (int x = 0; x < 10; x++) {
        cout << "|" << x << "|";
        for (int y = 0; y < 10; y++) {
            arr[x][y] = ' ';
        }
        cout << endl;
    }
}

//выбор второй палубы корабля
//данная проверка нужна для того, что бы ячейки не перескакивали с одного края поля на другой
//если у нас х=0, то у можно поставить на другом краю поля, поэтому нужно исключить проверку поля слева, если у=9
bool The_choice_of_the_second_deck(int x, int y, char arr[SIZE][SIZE], char Sym_Ship) {
    if (y == 9 && (arr[x - 1][y] == Sym_Ship || arr[x + 1][y] == Sym_Ship || arr[x][y - 1] == Sym_Ship))
        return true;
    else if (y != 9 && (arr[x - 1][y] == Sym_Ship || arr[x + 1][y] == Sym_Ship || arr[x][y - 1] == Sym_Ship || arr[x][y + 1] == Sym_Ship))
        return true;
    else
        return false;
}

//функция проверки свободных ячеек вокруг двухпалубных кораблей во все стороны
bool Checking_cells_2_up(char arr[SIZE][SIZE], int x, int y) {
    //проверка свободных ячeeк вокруг координаты вверх
    bool A=true;
    for (int i = -2; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R' || arr[x + i][y + j] == 'T') {
                //проверка края поля, иначе будут съезжать ячейки
                if ((x == 0 && i < 0) || (x == 9 && i > 0) || (y == 0 && j < 0) || (y == 9 && j > 0)) {
                    continue;
                }
                else {
                    A = false;
                    break;
                }
            }
        }
        if (!A)
            return A;
    }
}
bool Checking_cells_2_right(char arr[SIZE][SIZE], int x, int y) {
    //проверка свободных ячeeк вокруг координаты вправо
    bool B = true;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 3; j++) {
            if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R' || arr[x + i][y + j] == 'T') {
                //проверка края поля, иначе будут съезжать ячейки
                if ((x == 0 && i < 0) || (x == 9 && i > 0) || (y == 0 && j < 0) || (y == 9 && j > 0)) {
                    continue;
                }
                else {
                    B = false;
                    break;
                }
            }
        }
        if (!B)
            return B;
    }
}
bool Checking_cells_2_down(char arr[SIZE][SIZE], int x, int y) {
    //проверка свободных ячeeк вокруг координаты вниз
    bool C = true;
    for (int i = -1; i < 3; i++) {
        for (int j = -1; j < 2; j++) {
            if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R' || arr[x + i][y + j] == 'T') {
                //проверка края поля, иначе будут съезжать ячейки
                if ((x == 0 && i < 0) || (x == 9 && i > 0) || (y == 0 && j < 0) || (y == 9 && j > 0)) {
                    continue;
                }
                else {
                    C = false;
                    break;
                }
            }
        }
        if (!C)
            return C;
    }
}
bool Checking_cells_2_left(char arr[SIZE][SIZE], int x, int y) {
    //проверка свободных ячeeк вокруг координаты влево
    bool D = true;
    for (int i = -1; i < 2; i++) {
        for (int j = -2; j < 2; j++) {
            if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R' || arr[x + i][y + j] == 'T') {
                //проверка края поля, иначе будут съезжать ячейки
                if ((x == 0 && i < 0) || (x == 9 && i > 0) || (y == 0 && j < 0) || (y == 9 && j > 0)) {
                    continue;
                }
                else {
                    D = false;
                    break;
                }
            }
        }
        if (!D)
            return D;
    }
}

//проверка наличия кораблей вокруг ячейки на один ход
bool Check_the_ships_around(char arr[SIZE][SIZE], int x, int y) {
    bool A = true;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (arr[x + i][y + j] == 'K') {
                //проверка края поля, иначе будут съeзжать ячейки
                if ((x == 0 && i < 0) || (x == 9 && i > 0) || (y == 0 && j < 0) || (y == 9 && j > 0)) {
                    continue;
                }
                else {
                    A = false;
                    break;
                }
            }
        }
        if (!A)
            break;
    }
    return A;
}
//перегрузка для второго двухпалубного корабля
bool Check_the_ships_around(char arr[SIZE][SIZE], int x, int y, char Sym_Ship) {
    bool A = true;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (arr[x + i][y + j] == 'K'|| arr[x + i][y + j] == Sym_Ship) {
                //проверка края поля, иначе будут съeзжать ячейки
                if ((x == 0 && i < 0) || (x == 9 && i > 0) || (y == 0 && j < 0) || (y == 9 && j > 0)) {
                    continue;
                }
                else {
                    A = false;
                    break;
                }
            }
        }
        if (!A)
            break;
    }
    return A;
}

//перегрузка для третьего двухпалубного корабля
bool Check_the_ships_around(char arr[SIZE][SIZE], int x, int y, char Sym_Ship, char Sym_Ship_2) {
    bool A = true;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == Sym_Ship || arr[x + i][y + j] == Sym_Ship_2) {
                //проверка края поля, иначе будут съeзжать ячейки
                if ((x == 0 && i < 0) || (x == 9 && i > 0) || (y == 0 && j < 0) || (y == 9 && j > 0)) {
                    continue;
                }
                else {
                    A = false;
                    break;
                }
            }
        }
        if (!A)
            break;
    }
    return A;
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
