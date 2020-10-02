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
RR-������ ������������ �������*/

// �������� ������� ������ � ����������
//������� ����������� ������������ �������� ������� ������
void Rasstanovka_kor(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "������� ���������� ������������� ������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e'
                && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ���������� ������������� ������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
        //�������� ��������� ��ee� ������ ����������
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
//������� ����������� ������������ �������� ������� ������
//������ ������������ �������
//������ ������
void Rasstanovka_kor_2_pal_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "������� ���������� ������� ������������� ������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ���������� ������� ������������� ������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
        //�������� ��������� ��ee� ������ ����������
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
//������ ������
void Rasstanovka_kor_2_pal_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "������� ���������� ������� ������������� ������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ���������� ������� ������������� ������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ �������� 
        //� ���� ����� ������ �������
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
        //�������� ������� ����� ������ ������ ������������� ������� ���������������
        if (Result_vybora) {
            if (arr[x - 1][y] == 'D' || arr[x + 1][y] == 'D' || arr[x][y - 1] == 'D' || arr[x][y + 1] == 'D')
                break;
            else
                Result_vybora = false;
        }
    } while (!Result_vybora);

    arr[x][y] = 'D';
}
//������ ������������ ������� ������
//������ ������
void Rasstanovka_kor_2_2_pal_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "������� ���������� ������� ������������� ������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ���������� ������� ������������� ������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
        //�������� ��������� ��ee� ������ ����������
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
//������ ������
void Rasstanovka_kor_2_2_pal_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "������� ���������� ������� ������������� ������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ���������� ������� ������������� ������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ �������� 
        //� ���� ����� ������ ������� �������
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
        //�������� ������� ����� ������ ������ ������������� �������, ������� �� ������
        if (Result_vybora) {
            if (arr[x - 1][y] == 'G' || arr[x + 1][y] == 'G' || arr[x][y - 1] == 'G' || arr[x][y + 1] == 'G')
                break;
            else
                Result_vybora = false;
        }
    } while (!Result_vybora);

    arr[x][y] = 'G';
}

//������ ������������ ������� ������
//������ ������
void Rasstanovka_kor_2_3_pal_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "������� ���������� �������� ������������� ������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ���������� �������� ������������� ������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
        //�������� ��������� ��ee� ������ ����������
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
//������ ������
void Rasstanovka_kor_2_3_pal_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    bool Result_vybora;
    do {
        Result_vybora = true;
        do {
            do {
                cout << "������� ���������� ������� ������������� ������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ���������� ������� ������������� ������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ �������� 
        //� ���� ����� ������  �������
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
        //�������� ������� ����� ������ ������ ������������� �������
        if (Result_vybora) {
            if (arr[x - 1][y] == 'R' || arr[x + 1][y] == 'R' || arr[x][y - 1] == 'R' || arr[x][y + 1] == 'R')
                break;
            else
                Result_vybora = false;
        }
    } while (!Result_vybora);

    arr[x][y] = 'R';
}


////////////////////////����������� �������� �����������///////////////////////////////
//������� ����������� ������������ �������� ����������
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

//������� ����������� ������������ �������� �����������
//������ ������������ �������
//������ ������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
        //�������� ��������� ��ee� ������ ����������
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
//������ ������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ �������� 
        //� ���� ����� ������ �������
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
        //�������� ������� ����� ������ ������ ������������� �������
        if (Result_vybora) {
            if (arr[x - 1][y] == 'D' || arr[x + 1][y] == 'D' || arr[x][y - 1] == 'D' || arr[x][y + 1] == 'D')
                break;
            else
                Result_vybora = false;
        }
    } while (!Result_vybora);

    arr[x][y] = 'D';
}
//������ ������������ �������
//������ ������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
        //�������� ��������� ��ee� ������ ����������
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
//������ ������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ �������� 
        //� ���� ����� �������������
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
        //�������� ������� ����� ������ ������ ������������� �������
        if (Result_vybora) {
            if (arr[x - 1][y] == 'G' || arr[x + 1][y] == 'G' || arr[x][y - 1] == 'G' || arr[x][y + 1] == 'G')
                break;
            else
                Result_vybora = false;
        }
    } while (!Result_vybora);

    arr[x][y] = 'G';
}
//������ ������������ �������
//������ ������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ ��������
        //�������� ��������� ��ee� ������ ����������
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
//������ ������
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
        //���� ����������� ���� �� �� ������� �� ��������� ������, � ������� ��� ������ �������� 
        //� ���� ����� �������������
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
        //�������� ������� ����� ������ ������ ������������� �������
        if (Result_vybora) {
            if (arr[x - 1][y] == 'R' || arr[x + 1][y] == 'R' || arr[x][y - 1] == 'R' || arr[x][y + 1] == 'R')
                break;
            else
                Result_vybora = false;
        }
    } while (!Result_vybora);

    arr[x][y] = 'R';
}

///////////////////////////////������� ���� ������/����������////////////////////////////////////////////
//������� ���� ������ ������ ����������
int HodIgr(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "������� ������ ���������� (�������) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e'
                && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "������� ������ ���������� (������) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
        return 1;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ �������
    }
    else if (arr[x][y] == 'D') {
        arr[x][y] = 'O';
        return 2;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ ������� DD
    }
    else if (arr[x][y] == 'G') {
        arr[x][y] = 'O';
        return 3;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ ������� GG
    }
    else if (arr[x][y] == 'R') {
        arr[x][y] = 'O';
        return 4;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ ������� RR
    }
    else {
        arr[x][y] = '*';
        return 0;
    }
}


/*//������� ���� ����������
int HodKomp(char arr[SIZE][SIZE])
{
    int x, y;
    do {
        do {
            x = rand() % 10;               //������
        } while (x < 0 || x > 9);
        do {
            y = rand() % 10;              //�������
        } while (y < 0 || y > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
        return 1;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ �������
    }
    else if (arr[x][y] == 'D') {
        arr[x][y] = 'O';
        return 2;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ ������� DD
    }
    else if (arr[x][y] == 'G') {
        arr[x][y] = 'O';
        return 3;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ ������� GG
    }
    else if (arr[x][y] == 'R') {
        arr[x][y] = 'O';
        return 4;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ ������� RR
    }
    else {
        arr[x][y] = '*';
        return 0;
    }
}*/

//������� ���� ����������
int HodKomp(char arr[SIZE][SIZE], int &x, int &y, bool Ship_DD, bool Ship_GG, bool Ship_RR)
{
    //���� ������� ���������� ������, �� ��������� ������� ��������� ����
    if (!Ship_DD&&!Ship_GG&&!Ship_RR) {
        do {
            do {
                x = rand() % 10;               //������
            } while (x < 0 || x > 9);
            do {
                y = rand() % 10;              //�������
            } while (y < 0 || y > 9);
        } while (arr[x][y] == '*' || arr[x][y] == 'O');
        if (arr[x][y] == 'K') {
            arr[x][y] = 'O';
            return 1;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ �������
        }
        else if (arr[x][y] == 'D') {
            arr[x][y] = 'O';
            return 2;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ ������� DD
        }
        else if (arr[x][y] == 'G') {
            arr[x][y] = 'O';
            return 3;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ ������� GG
        }
        else if (arr[x][y] == 'R') {
            arr[x][y] = 'O';
            return 4;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ ������� RR
        }
        else {
            arr[x][y] = '*';
            return 0;
        }
    }
    //���� ������� ���������� ��������, �� ��������� ������� ���� �� ���� ����������� ������ �������� �������
    else if (Ship_DD) {
        bool Cycle = false;
        do {
            int �oordinate = rand() % 4; //���������� ��� ������ ���������� ���������� (��������� �������� ����� ������ ������ ������������� ������� DD)
            switch (�oordinate) {
            case 0: {
                if (arr[x - 1][y] == 'D') {
                    arr[x - 1][y] = 'O';
                    Cycle = true;
                    return 2;
                }
                else if (arr[x - 1][y] == ' ') {
                    arr[x - 1][y] = '*';
                    Cycle = true;
                    return 0;
                }
                else Cycle = false;
            } break;
            case 1: {
                if (arr[x][y + 1] == 'D') {
                    arr[x][y + 1] = 'O';
                    Cycle = true;
                    return 2;
                }
                else if (arr[x][y + 1] == ' ') {
                    arr[x][y + 1] = '*';
                    Cycle = true;
                    return 0;
                }
                else Cycle = false;
            } break;
            case 2: {
                if (arr[x + 1][y] == 'D') {
                    arr[x + 1][y] = 'O';
                    Cycle = true;
                    return 2;
                }
                else if (arr[x + 1][y] == ' ') {
                    arr[x + 1][y] = '*';
                    Cycle = true;
                    return 0;
                }
                else Cycle = false;
            } break;
            case 3: {
                if (arr[x][y - 1] == 'D') {
                    arr[x][y - 1] = 'O';
                    Cycle = true;
                    return 2;
                }
                else if (arr[x][y - 1] == ' ') {
                    arr[x][y - 1] = '*';
                    Cycle = true;
                    return 0;
                }
                else Cycle = false;
            } break;
            }
        } while (!Cycle);
    }
    else if (Ship_GG) {
        bool Cycle = false;
        do {
            int �oordinate = rand() % 4; //���������� ��� ������ ���������� ���������� (��������� �������� ����� ������ ������ ������������� ������� DD)
            switch (�oordinate) {
            case 0: {
                if (arr[x - 1][y] == 'G') {
                    arr[x - 1][y] = 'O';
                    Cycle = true;
                    return 3;
                }
                else if (arr[x - 1][y] == ' ') {
                    arr[x - 1][y] = '*';
                    Cycle = true;
                    return 0;
                }
                else Cycle = false;
            } break;
            case 1: {
                if (arr[x][y + 1] == 'G') {
                    arr[x][y + 1] = 'O';
                    Cycle = true;
                    return 3;
                }
                else if (arr[x][y + 1] == ' ') {
                    arr[x][y + 1] = '*';
                    Cycle = true;
                    return 0;
                }
                else Cycle = false;
            } break;
            case 2: {
                if (arr[x + 1][y] == 'G') {
                    arr[x + 1][y] = 'O';
                    Cycle = true;
                    return 3;
                }
                else if (arr[x + 1][y] == ' ') {
                    arr[x + 1][y] = '*';
                    Cycle = true;
                    return 0;
                }
                else Cycle = false;
            } break;
            case 3: {
                if (arr[x][y - 1] == 'G') {
                    arr[x][y - 1] = 'O';
                    Cycle = true;
                    return 3;
                }
                else if (arr[x][y - 1] == ' ') {
                    arr[x][y - 1] = '*';
                    Cycle = true;
                    return 0;
                }
                else Cycle = false;
            } break;
            }
        } while (!Cycle);
    }
    else if (Ship_RR) {
    bool Cycle = false;
    do {
        int �oordinate = rand() % 4; //���������� ��� ������ ���������� ���������� (��������� �������� ����� ������ ������ ������������� ������� DD)
        switch (�oordinate) {
        case 0: {
            if (arr[x - 1][y] == 'R') {
                arr[x - 1][y] = 'O';
                Cycle = true;
                return 4;
            }
            else if (arr[x - 1][y] == ' ') {
                arr[x - 1][y] = '*';
                Cycle = true;
                return 0;
            }
            else Cycle = false;
        } break;
        case 1: {
            if (arr[x][y + 1] == 'R') {
                arr[x][y + 1] = 'O';
                Cycle = true;
                return 4;
            }
            else if (arr[x][y + 1] == ' ') {
                arr[x][y + 1] = '*';
                Cycle = true;
                return 0;
            }
            else Cycle = false;
        } break;
        case 2: {
            if (arr[x + 1][y] == 'R') {
                arr[x + 1][y] = 'O';
                Cycle = true;
                return 4;
            }
            else if (arr[x + 1][y] == ' ') {
                arr[x + 1][y] = '*';
                Cycle = true;
                return 0;
            }
            else Cycle = false;
        } break;
        case 3: {
            if (arr[x][y - 1] == 'R') {
                arr[x][y - 1] = 'O';
                Cycle = true;
                return 4;
            }
            else if (arr[x][y - 1] == ' ') {
                arr[x][y - 1] = '*';
                Cycle = true;
                return 0;
            }
            else Cycle = false;
        } break;
        }
    } while (!Cycle);
    }
}


