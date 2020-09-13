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

//функция расстановки однопалубных кораблей первого игрока
void Rasstanovka_kor(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    //расстановка однопалубных кораблей
    do {
        Result_vybora = true;
        do {
            do {
                cout << "Укажите первую координату однопалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату однопалубного корабля (строка) "; cin >> x;
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг кораблей
        //проверка свободных ячeeк вокруг координаты
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        int a = x;
        int b = y;
        for ((x - 1); x < (a + 3); x++) {
            for ((y - 1); y < (b + 3); y++) {
                if (arr[x - 1][y - 1] == 'D' || arr[x - 1][y - 1] == 'K') {
                    Result_vybora = false;
                    break;
                }
            }
            if (Result_vybora == false)
                break;
        }
    } while (Result_vybora==false);
        /*(arr[x][y] == 'K' ||
        //координаты соседних клеток крест накрест
        arr[x - 1][y] == 'K' || arr[x + 1][y] == 'K' || arr[x][y - 1] == 'K' || arr[x][y + 1] == 'K'
        //по диагонали
        || arr[x - 1][y + 1] == 'K' || arr[x + 1][y + 1] == 'K' || arr[x - 1][y - 1] == 'K' || arr[x + 1][y - 1] == 'K');*/
    arr[x-3][y-3] = 'K';
}
//функция расстановки двухпалубных кораблей первого игрока - первая палуба
//первая палуба
void Rasstanovka_kor_2_pal_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "Укажите первую координату двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату двухпалубного корабля (строка) "; cin >> x;
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг однопалубных кораблей и
    } while (arr[x][y] == 'D' || arr[x][y] == 'K' ||
        //координаты соседних клеток крест накрест (там не должно быть кораблей)
        arr[x - 1][y] == 'K' || arr[x + 1][y] == 'K' || arr[x][y - 1] == 'K' || arr[x][y + 1] == 'K'
        //по диагонали (там не должно быть кораблей)
        || arr[x - 1][y + 1] == 'K' || arr[x + 1][y + 1] == 'K' || arr[x - 1][y - 1] == 'K' || arr[x + 1][y - 1] == 'K');
    arr[x][y] = 'D';
}
//функция расстановки двухпалубных кораблей первого игрока - вторая палуба
void Rasstanovka_kor_2_pal_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "Укажите первую координату двухпалубного корабля (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату двухпалубного корабля (строка) "; cin >> x;
        } while (x < 0 || x > 9);
        //цикл повторяется пока вы не попадем на свободную клетку, у которой нет вокруг однопалубных кораблей и есть рядом первая палуба двухпалубного корабля
    } while ((arr[x][y] == 'D' || arr[x][y] == 'K' ||
        //координаты соседних клеток крест накрест (там не должно быть кораблей)
        arr[x - 1][y] == 'K' || arr[x + 1][y] == 'K' || arr[x][y - 1] == 'K' || arr[x][y + 1] == 'K'
        //по диагонали (там не должно быть кораблей)
        || arr[x - 1][y + 1] == 'K' || arr[x + 1][y + 1] == 'K' || arr[x - 1][y - 1] == 'K' || arr[x + 1][y - 1] == 'K'
        //по диагонали (там не должно быть кораблей)
        || arr[x - 1][y + 1] == 'D' || arr[x + 1][y + 1] == 'D' || arr[x - 1][y - 1] == 'D' || arr[x + 1][y - 1] == 'D')
        // проверка есть ли рядом палуба двухпалубного корабля крест накрест (в одной из клеток должна быть палуба двухпалубного корабля)
        || (arr[x - 1][y] != 'D' || arr[x + 1][y] != 'D' || arr[x][y - 1] != 'D' || arr[x][y + 1] != 'D'));
    arr[x][y] = 'D';
}

//функция расстановки кораблей второго игрока
void Rasstanovka_kor_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "Укажите первую координату (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату (строка) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == 'K' ||
        //координаты соседних клеток крест накрест
        arr[x - 1][y] == 'H' || arr[x + 1][y] == 'H' || arr[x][y - 1] == 'H' || arr[x][y + 1] == 'H'
        //по диагонали
        || arr[x - 1][y + 1] == 'H' || arr[x + 1][y + 1] == 'H' || arr[x - 1][y - 1] == 'H' || arr[x + 1][y - 1] == 'H');
    //корабль указывается в виде символа Н для различия от игрока №1
    arr[x][y] = 'H';
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

//функция расстановки кораблей компьютера
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

//функция хода игрока против компьютера
bool HodIgr(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "Укажите первую координату (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату (строка) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
        return true;   //для повторного удара в случае истины
    }
    else {
        arr[x][y] = '*';
        return false;
    }
}

//функция хода первого игрока
bool HodIgr_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "Укажите первую координату (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату (строка) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'H') {
        arr[x][y] = 'O';
        return true;   //для повторного удара в случае истины
    }
    else {
        arr[x][y] = '*';
        return false;
    }
}

//функция хода второго игрока
bool HodIgr_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "Укажите первую координату (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату (строка) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
        return true;   //для повторного удара в случае истины
    }
    else {
        arr[x][y] = '*';
        return false;
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

//функция хода компьютера
bool HodKomp(char arr[SIZE][SIZE])
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
        return true; //для повторного удара в случае истины
    }
    else {
        arr[x][y] = '*';
        return false;
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