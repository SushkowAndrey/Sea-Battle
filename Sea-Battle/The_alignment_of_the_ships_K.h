#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "Other_Fun.h"

using namespace std;

/*������ �������� ��� ������ � ���������� - �����������
�-������������ �������
DD-������ ������������ �������
GG-������ ������������ �������
RR-������ ������������ �������
TTT-������ ������������ �������*/
// ���������� ���� �������� ����������� �������� - ������ �, �������� - ������� �

////////////////////////����������� �������� �����������///////////////////////////////
//������� ����������� ������������ �������� ����������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
      //�������� ��������� ��ee� ������ ����������
        Result_vybora = Check_the_ships_around(arr, x, y);
    } while (!Result_vybora);
    //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
    //�������� ��������� ��ee� ������ ����������
    arr[x][y] = 'K';
}

//������� ����������� ������������ �������� �����������
//������ ������������ �������
//������ ������
void Rasstanovka_kor_2_pal_1_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora1, Result_vybora2, Result_vybora3, Result_vybora4;
    do {
        Result_vybora1 = true, Result_vybora2 = true, Result_vybora3 = true, Result_vybora4 = true;
        do {
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
        } while (y < 0 || y > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
        //�������� ��������� ��ee� ������ ����������
        Result_vybora1 = Checking_cells_2_up(arr, x, y);
        Result_vybora2 = Checking_cells_2_right(arr, x, y);
        Result_vybora3 = Checking_cells_2_down(arr, x, y);
        Result_vybora4 = Checking_cells_2_left(arr, x, y);
    } while (!Result_vybora1 && !Result_vybora2 && !Result_vybora3 && !Result_vybora4);
    arr[x][y] = 'D';
}
//������ ������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ �������� 
        //� ���� ����� ������ �������
        Result_vybora = Check_the_ships_around(arr, x, y);
        //�������� ������� ����� ������ ������ ������������� ������� ���������������
        if (Result_vybora) {
            //������ �������� ����� ��� ����, ��� �� ������ �� ������������� � ������ ���� ���� �� ������
            //���� � ��� �=0, �� � ����� ��������� �� ������ ���� ����, ������� ����� ��������� �������� ���� �����, ���� �=9
            Result_vybora = The_choice_of_the_second_deck(x, y, arr, 'D');
        }
    } while (!Result_vybora);

    arr[x][y] = 'D';
}
//������ ������������ �������
//������ ������
void Rasstanovka_kor_2_2_pal_1_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora1, Result_vybora2, Result_vybora3, Result_vybora4;
    do {
        Result_vybora1 = true, Result_vybora2 = true, Result_vybora3 = true, Result_vybora4 = true;
        do {
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
        } while (y < 0 || y > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
        //�������� ��������� ��ee� ������ ����������
        Result_vybora1 = Checking_cells_2_up(arr, x, y);
        Result_vybora2 = Checking_cells_2_right(arr, x, y);
        Result_vybora3 = Checking_cells_2_down(arr, x, y);
        Result_vybora4 = Checking_cells_2_left(arr, x, y);
    } while (!Result_vybora1 && !Result_vybora2 && !Result_vybora3 && !Result_vybora4);
    arr[x][y] = 'G';
}
//������ ������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ �������� 
        //� ���� ����� ������ ������� �������
        Result_vybora = Check_the_ships_around(arr, x, y, 'D');
        //�������� ������� ����� ������ ������ ������������� �������, ������� �� ������
        if (Result_vybora) {
            //������ �������� ����� ��� ����, ��� �� ������ �� ������������� � ������ ���� ���� �� ������
            //���� � ��� �=0, �� � ����� ��������� �� ������ ���� ����, ������� ����� ��������� �������� ���� �����, ���� �=9
            Result_vybora = The_choice_of_the_second_deck(x, y, arr, 'G');
        }
    } while (!Result_vybora);

    arr[x][y] = 'G';
}
//������ ������������ �������
//������ ������
void Rasstanovka_kor_2_3_pal_1_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    bool Result_vybora1, Result_vybora2, Result_vybora3, Result_vybora4;
    do {
        Result_vybora1 = true, Result_vybora2 = true, Result_vybora3 = true, Result_vybora4 = true;
        do {
            x = rand() % 10;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;
        } while (y < 0 || y > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
        //�������� ��������� ��ee� ������ ����������
        Result_vybora1 = Checking_cells_2_up(arr, x, y);
        Result_vybora2 = Checking_cells_2_right(arr, x, y);
        Result_vybora3 = Checking_cells_2_down(arr, x, y);
        Result_vybora4 = Checking_cells_2_left(arr, x, y);
    } while (!Result_vybora1 && !Result_vybora2 && !Result_vybora3 && !Result_vybora4);
    arr[x][y] = 'R';
}
//������ ������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ �������� 
        //� ���� ����� ������ �������
        Result_vybora = Check_the_ships_around(arr, x, y, 'D', 'G');
        //�������� ������� ����� ������ ������ ������������� ������� R
        if (Result_vybora) {
            //������ �������� ����� ��� ����, ��� �� ������ �� ������������� � ������ ���� ���� �� ������
            //���� � ��� �=0, �� � ����� ��������� �� ������ ���� ����, ������� ����� ��������� �������� ���� �����, ���� �=9
            Result_vybora = The_choice_of_the_second_deck(x, y, arr, 'R');
        }
    } while (!Result_vybora);
    arr[x][y] = 'R';
}

//������� ����������� ������������ �������� �����������
//������ ������������ �������
//������ ������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
        //�������� ��������� ��ee� ������ ����������
        for (int i = -1; i < 4; i++) { //�������� ��������� ����
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_1 = false;
                    break;
                }
            }
            if (!Result_vybora_1)
                break;
        }
        for (int i = -1; i < 2; i++) {//�������� ��������� ������
            for (int j = -1; j < 4; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_2 = false;
                    break;
                }
            }
            if (!Result_vybora_2)
                break;
        }
        for (int i = -3; i < 2; i++) {//�������� ��������� �����
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_3 = false;
                    break;
                }
            }
            if (!Result_vybora_3)
                break;
        }
        for (int i = -1; i < 2; i++) {//�������� ��������� �����
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
//������ ������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ �������� 
        //� ���� ����� ������  �������
        for (int i = -2; i < 3; i++) { //�������� ��������� ���� (�� 1 ������ ������ ������, �� ���� ������ ��� ������� � �� ��� ��� ���������)
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_1 = false;
                    break;
                }
            }
            if (!Result_vybora_1)
                break;
        }
        for (int i = -1; i < 2; i++) {//�������� ��������� ������
            for (int j = -2; j < 3; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_2 = false;
                    break;
                }
            }
            if (!Result_vybora_2)
                break;
        }
        for (int i = -2; i < 3; i++) {//�������� ��������� �����
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_3 = false;
                    break;
                }
            }
            if (!Result_vybora_3)
                break;
        }
        for (int i = -1; i < 2; i++) {//�������� ��������� �����
            for (int j = -2; j < 3; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_4 = false;
                    break;
                }
            }
            if (!Result_vybora_4)
                break;
        }
        //�������� ������� ����� ������ ������ �������������� �������
        if (Result_vybora_1) { //��������� ���� �� ������ ������ ��� ��������� �����������
            if (arr[x - 1][y] == 'T') Result_vybora_1 = true;
            else Result_vybora_1 = false;
        }
        if (Result_vybora_2) { //��������� ���� �� ������ ������ ����� ��������� �����������
            if (arr[x][y - 1] == 'T') Result_vybora_2 = true;
            else Result_vybora_2 = false;
        }
        if (Result_vybora_3) { //��������� ���� �� ������ ������ ��� ��������� �����������
            if (arr[x + 1][y] == 'T') Result_vybora_3 = true;
            else Result_vybora_3 = false;
        }
        if (Result_vybora_4) { //��������� ���� �� ������ ������ ����� ��������� �����������
            if (arr[x][y + 1] == 'T') Result_vybora_4 = true;
            else Result_vybora_4 = false;
        }
    } while (!Result_vybora_1 && !Result_vybora_2 && !Result_vybora_3 && !Result_vybora_4);
    arr[x][y] = 'T';
}

//������ ������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ �������� 
        //� ���� ����� ������  �������
        for (int i = -1; i < 2; i++) { //�������� ��������� ���� (��� �� 1 ������ ������ ������, �� ��� ������ ��� ������� � �� ��� ��� ���������)
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_1 = false;
                    break;
                }
            }
            if (!Result_vybora_1)
                break;
        }
        for (int i = -1; i < 2; i++) {//�������� ��������� ������
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_2 = false;
                    break;
                }
            }
            if (!Result_vybora_2)
                break;
        }
        for (int i = -1; i < 2; i++) {//�������� ��������� �����
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_3 = false;
                    break;
                }
            }
            if (!Result_vybora_3)
                break;
        }
        for (int i = -1; i < 2; i++) {//�������� ��������� �����
            for (int j = -1; j < 2; j++) {
                if (arr[x + i][y + j] == 'K' || arr[x + i][y + j] == 'D' || arr[x + i][y + j] == 'G' || arr[x + i][y + j] == 'R') {
                    Result_vybora_4 = false;
                    break;
                }
            }
            if (!Result_vybora_4)
                break;
        }
        //�������� ������� ����� ������ ������ �������������� �������
        if (Result_vybora_1) { //��������� ���� �� ������ � ������ ������ ��� ��������� �����������
            if (arr[x - 1][y] == 'T' && arr[x - 2][y] == 'T') Result_vybora_1 = true;
            else Result_vybora_1 = false;
        }
        if (Result_vybora_2) { //��������� ���� �� ������ � ������ ������ ����� ��������� �����������
            if (arr[x][y - 1] == 'T' && arr[x][y - 2] == 'T') Result_vybora_2 = true;
            else Result_vybora_2 = false;
        }
        if (Result_vybora_3) { //��������� ���� �� ������ � ������ ������ ��� ��������� �����������
            if (arr[x + 1][y] == 'T' && arr[x + 2][y] == 'T') Result_vybora_3 = true;
            else Result_vybora_3 = false;
        }
        if (Result_vybora_4) { //��������� ���� �� ������ � ������ ������ ����� ��������� �����������
            if (arr[x][y + 1] == 'T' && arr[x][y + 2] == 'T') Result_vybora_4 = true;
            else Result_vybora_4 = false;
        }
    } while (!Result_vybora_1 && !Result_vybora_2 && !Result_vybora_3 && !Result_vybora_4);
    arr[x][y] = 'T';
}
