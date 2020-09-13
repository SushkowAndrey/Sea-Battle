#pragma once
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int SIZE = 10;

// �������� �������
//������� ������ ���������� �������� ���������� ������� �� �����
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

//������� ����������� ������������ �������� ������� ������
void Rasstanovka_kor(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    //����������� ������������ ��������
    do {
        Result_vybora = true;
        do {
            do {
                cout << "������� ������ ���������� ������������� ������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ������ ���������� ������������� ������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
        //�������� ��������� ��ee� ������ ����������
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
        //���������� �������� ������ ����� �������
        arr[x - 1][y] == 'K' || arr[x + 1][y] == 'K' || arr[x][y - 1] == 'K' || arr[x][y + 1] == 'K'
        //�� ���������
        || arr[x - 1][y + 1] == 'K' || arr[x + 1][y + 1] == 'K' || arr[x - 1][y - 1] == 'K' || arr[x + 1][y - 1] == 'K');*/
    arr[x-3][y-3] = 'K';
}
//������� ����������� ������������ �������� ������� ������ - ������ ������
//������ ������
void Rasstanovka_kor_2_pal_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "������� ������ ���������� ������������� ������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ������ ���������� ������������� ������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ������������ �������� �
    } while (arr[x][y] == 'D' || arr[x][y] == 'K' ||
        //���������� �������� ������ ����� ������� (��� �� ������ ���� ��������)
        arr[x - 1][y] == 'K' || arr[x + 1][y] == 'K' || arr[x][y - 1] == 'K' || arr[x][y + 1] == 'K'
        //�� ��������� (��� �� ������ ���� ��������)
        || arr[x - 1][y + 1] == 'K' || arr[x + 1][y + 1] == 'K' || arr[x - 1][y - 1] == 'K' || arr[x + 1][y - 1] == 'K');
    arr[x][y] = 'D';
}
//������� ����������� ������������ �������� ������� ������ - ������ ������
void Rasstanovka_kor_2_pal_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "������� ������ ���������� ������������� ������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ������ ���������� ������������� ������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ������������ �������� � ���� ����� ������ ������ ������������� �������
    } while ((arr[x][y] == 'D' || arr[x][y] == 'K' ||
        //���������� �������� ������ ����� ������� (��� �� ������ ���� ��������)
        arr[x - 1][y] == 'K' || arr[x + 1][y] == 'K' || arr[x][y - 1] == 'K' || arr[x][y + 1] == 'K'
        //�� ��������� (��� �� ������ ���� ��������)
        || arr[x - 1][y + 1] == 'K' || arr[x + 1][y + 1] == 'K' || arr[x - 1][y - 1] == 'K' || arr[x + 1][y - 1] == 'K'
        //�� ��������� (��� �� ������ ���� ��������)
        || arr[x - 1][y + 1] == 'D' || arr[x + 1][y + 1] == 'D' || arr[x - 1][y - 1] == 'D' || arr[x + 1][y - 1] == 'D')
        // �������� ���� �� ����� ������ ������������� ������� ����� ������� (� ����� �� ������ ������ ���� ������ ������������� �������)
        || (arr[x - 1][y] != 'D' || arr[x + 1][y] != 'D' || arr[x][y - 1] != 'D' || arr[x][y + 1] != 'D'));
    arr[x][y] = 'D';
}

//������� ����������� �������� ������� ������
void Rasstanovka_kor_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "������� ������ ���������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ������ ���������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == 'K' ||
        //���������� �������� ������ ����� �������
        arr[x - 1][y] == 'H' || arr[x + 1][y] == 'H' || arr[x][y - 1] == 'H' || arr[x][y + 1] == 'H'
        //�� ���������
        || arr[x - 1][y + 1] == 'H' || arr[x + 1][y + 1] == 'H' || arr[x - 1][y - 1] == 'H' || arr[x + 1][y - 1] == 'H');
    //������� ����������� � ���� ������� � ��� �������� �� ������ �1
    arr[x][y] = 'H';
}

// ������� �������������� ������� ���������
void Gor_Granica(char* arr, int size) {
    for (int i = 0; i < (SIZE + 1); i++) {  //������� ������� ���������
        cout << "|" << *(arr + i) << "|";
    }
}

//������� ������ ��������
void Pokaz_Ship(char arr[SIZE][SIZE]) {
    for (int x = 0; x < 10; x++) {
        cout << "|" << x << "|";
        for (int y = 0; y < 10; y++) {
            cout << "|" << arr[x][y] << "|";
        }
        cout << endl;
    }
}

//������� ����������� �������� ����������
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

//������� ���� ������ ������ ����������
bool HodIgr(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "������� ������ ���������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ������ ���������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
        return true;   //��� ���������� ����� � ������ ������
    }
    else {
        arr[x][y] = '*';
        return false;
    }
}

//������� ���� ������� ������
bool HodIgr_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "������� ������ ���������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ������ ���������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'H') {
        arr[x][y] = 'O';
        return true;   //��� ���������� ����� � ������ ������
    }
    else {
        arr[x][y] = '*';
        return false;
    }
}

//������� ���� ������� ������
bool HodIgr_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "������� ������ ���������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ������ ���������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
        return true;   //��� ���������� ����� � ������ ������
    }
    else {
        arr[x][y] = '*';
        return false;
    }
}

//������� ����������� ����������� ���� (�������� ������� � ������� ������ � ����������)
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

//������� ���� ����������
bool HodKomp(char arr[SIZE][SIZE])
{
    int x, y;
    do {
        do {
            x = rand() % 9;               //������
        } while (x < 0 || x > 9);
        do {
            y = rand() % 9;              //�������
        } while (y < 0 || y > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
        return true; //��� ���������� ����� � ������ ������
    }
    else {
        arr[x][y] = '*';
        return false;
    }
}

//������� �������� ���������� �������� ��������
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

//������� ����������� ����������� ���� ���� ������� (�������� ������� � ������� ������� � ������� ������)
void Pokaz_Udar_2(char arr1[SIZE][SIZE], char arr2[SIZE][SIZE]) {
    for (int x = 0; x < 10; x++) {
        cout << "|" << x << "|";    //����������� ������� ��������� �� �����
        for (int y = 0; y < 10; y++) {
            if (arr1[x][y] == 'O' || arr1[x][y] == '*') {
                cout << "|" << arr1[x][y] << "|";
            }
            else {
                cout << "| |";
            }
        }
        cout << "     ";
        cout << "|" << x << "|";//����������� ������� ��������� �� �����
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