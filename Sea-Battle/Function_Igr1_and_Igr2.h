#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "Other_Fun.h"

using namespace std;

// �������� �������

//������� ����������� �������� ������� ������
void Rasstanovka_kor_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "������� ������ ���������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' 
                && St != 'g' && St != 'h' && St != 'i' && St != 'j');
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

//������� ���� ������� ������
bool HodIgr_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "������� ������ ���������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' 
                && St != 'g' && St != 'h' && St != 'i' && St != 'j');
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



