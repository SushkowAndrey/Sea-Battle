#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "Other_Fun.h"

using namespace std;
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
        return 1;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ ������� K
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
    else if (arr[x][y] == 'T') {
        arr[x][y] = 'O';
        return 5;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������ ������� TTT
    }
    else {
        arr[x][y] = '*';
        return 0;
    }
}

//������� ���� ����������
int HodKomp(char arr[SIZE][SIZE], int& x, int& y, bool Ship_DD, bool Ship_GG, bool Ship_RR, bool Ship_TTT, int &�oordinate_3_TTT)
{
    //���� ������� ���������� ������, �� ��������� ������� ��������� ����
    if (!Ship_DD && !Ship_GG && !Ship_RR && !Ship_TTT) {
        bool Result_vybora = false;
        do {
            do {
                x = rand() % 10;               //������
            } while (x < 0 || x > 9);
            do {
                y = rand() % 10;              //�������
            } while (y < 0 || y > 9);
            if (arr[x][y] == '*') Result_vybora = false;
            // ���� �� �������� �������� ��������, �� ������� �� ���������� 1 ������ ���� �� ����� ������ �������� �������� �� ���� ������ ��� ������ ��������
            else {
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        if (arr[x + i][y + j] == 'O') {
                            Result_vybora = false;
                            break;
                        }
                        else Result_vybora = true;
                    }
                    if (!Result_vybora) break;
                }
            }
        } while (!Result_vybora); 
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
        else if (arr[x][y] == 'T') {
            arr[x][y] = 'O';
            return 5;   //��� ���������� ����� � ������ ������ ��� ��������� � ������������� ������� TTT
        }
        else {
            arr[x][y] = '*';
            return 0;
        }
    }
    //���� ������� ���������� ��������, �� ��������� ������� ���� �� ���� ����������� ������ �������� �������
    //���� �� ������������ ��������
    else if (Ship_DD) {
        //Repeated_strike(arr, x, y, 'D');-�� ��������
      bool Cycle = false; //���������� ��� ������� �����
        do {
            int �oordinate = rand() % 4; //���������� ��� ������ ���������� ���������� (��������� �������� ����� ������ ������ ������������� ������� RR)
            switch (�oordinate) {
            case 0: { //������� ������
                if (x==0) Cycle = false; //�������� ���� �������� ����
                else {
                    if (arr[x - 1][y] == 'D') {
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
            case 1: { //������ ������
                if (y == 9) Cycle = false;
                else {
                    if (arr[x][y + 1] == 'D') {
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
            case 2: { //������ ������
                if (x == 9) Cycle = false;
                else {
                    if (arr[x + 1][y] == 'D') {
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
            case 3: { //����� ������
                if (y == 0) Cycle = false;
                else {
                    if (arr[x][y - 1] == 'D') {
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
    else if (Ship_GG) {
        bool Cycle = false;
        do {
            int �oordinate = rand() % 4; //���������� ��� ������ ���������� ���������� (��������� �������� ����� ������ ������ ������������� ������� RR)
            switch (�oordinate) {
            case 0: { //������� ������
                if (x == 0) Cycle = false; //�������� ���� �������� ����
                else {
                    if (arr[x - 1][y] == 'G') {
                        arr[x - 1][y] = 'O';
                        Cycle = true;
                        return 3;
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
            case 1: { //������ ������
                if (y == 9) Cycle = false;
                else {
                    if (arr[x][y + 1] == 'G') {
                        arr[x][y + 1] = 'O';
                        Cycle = true;
                        return 3;
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
            case 2: { //������ ������
                if (x == 9) Cycle = false;
                else {
                    if (arr[x + 1][y] == 'G') {
                        arr[x + 1][y] = 'O';
                        Cycle = true;
                        return 3;
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
            case 3: { //����� ������
                if (y == 0) Cycle = false;
                else {
                    if (arr[x][y - 1] == 'G') {
                        arr[x][y - 1] = 'O';
                        Cycle = true;
                        return 3;
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
    else if (Ship_RR) {
        bool Cycle = false;
        do {
            int �oordinate = rand() % 4; //���������� ��� ������ ���������� ���������� (��������� �������� ����� ������ ������ ������������� ������� RR)
            switch (�oordinate) {
            case 0: { //������� ������
                if (x == 0) Cycle = false; //�������� ���� �������� ����
                else {
                    if (arr[x - 1][y] == 'R') {
                        arr[x - 1][y] = 'O';
                        Cycle = true;
                        return 4;
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
            case 1: { //������ ������
                if (y == 9) Cycle = false;
                else {
                    if (arr[x][y + 1] == 'R') {
                        arr[x][y + 1] = 'O';
                        Cycle = true;
                        return 4;
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
            case 2: { //������ ������
                if (x == 9) Cycle = false;
                else {
                    if (arr[x + 1][y] == 'R') {
                        arr[x + 1][y] = 'O';
                        Cycle = true;
                        return 4;
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
            case 3: { //����� ������
                if (y == 0) Cycle = false;
                else {
                    if (arr[x][y - 1] == 'R') {
                        arr[x][y - 1] = 'O';
                        Cycle = true;
                        return 4;
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
    ///////////////////////�� �������� ���������///////////////////
    else if (Ship_TTT) {
        if (�oordinate_3_TTT==0)//���� ���� ������ ���� ��������� � ������� ���
        {
            bool Cycle = false;
            do {
                �oordinate_3_TTT = 1 + rand() % 4; //���������� ��� ������ ���������� ���������� (��������� �������� ����� ������ ������ ������������� ������� TTT)
                switch (�oordinate_3_TTT) {
                case 1: { //������� ������
                    if (x == 0) Cycle = false; //�������� ���� �������� ����
                    else {
                        if (arr[x - 1][y] == 'T') {
                            arr[x - 1][y] = 'O';
                            Cycle = true;
                            return 5;
                        }
                        else if (arr[x - 1][y] == '*') {
                            Cycle = false;
                        }
                        else {
                            arr[x - 1][y] = '*';
                            Cycle = true;
                            �oordinate_3_TTT = 0;
                            return 0;
                        };
                    }
                } break;
                case 2: { //������ ������
                    if (y == 9) Cycle = false;
                    else {
                        if (arr[x][y + 1] == 'T') {
                            arr[x][y + 1] = 'O';
                            Cycle = true;
                            return 5;
                        }
                        else if (arr[x][y + 1] == '*') {
                            Cycle = false;
                        }
                        else {
                            arr[x][y + 1] = '*';
                            Cycle = true;
                            �oordinate_3_TTT = 0;
                            return 0;
                        };
                    }
                } break;
                case 3: { //������ ������
                    if (x == 9) Cycle = false;
                    else {
                        if (arr[x + 1][y] == 'T') {
                            arr[x + 1][y] = 'O';
                            Cycle = true;
                            return 5;
                        }
                        else if (arr[x + 1][y] == '*') {
                            Cycle = false;
                        }
                        else {
                            arr[x + 1][y] = '*';
                            Cycle = true;
                            �oordinate_3_TTT = 0;
                            return 0;
                        };
                    }
                } break;
                case 4: { //����� ������
                    if (y == 0) Cycle = false;
                    else {
                        if (arr[x][y - 1] == 'T') {
                            arr[x][y - 1] = 'O';
                            Cycle = true;
                            return 4;
                        }
                        else if (arr[x][y - 1] == '*') {
                            Cycle = false;
                        }
                        else {
                            arr[x][y - 1] = '*';
                            Cycle = true;
                            �oordinate_3_TTT = 0;
                            return 0;
                        };
                    }
                } break;
                }
            } while (!Cycle);
        }
        else if (�oordinate_3_TTT == 1) //������� ������
        {
            bool Cycle = false;
            do {
                int �oordinate_3_2_TTT = rand() % 2; //��������� ��������� ���������� ���� ������ ���� �����
                switch (�oordinate_3_2_TTT) {
                case 0: {
                    if (x == 1) Cycle = false; //�������� ���� �������� ����
                    else {  //���������� ������ ������
                        if (arr[x - 2][y] == 'T') {
                            arr[x - 2][y] = 'O';
                            Cycle = true;
                            return 5;
                        }
                        else if (arr[x - 2][y] == '*') {
                            Cycle = false;
                        }
                        else {
                            arr[x - 2][y] = '*';
                            Cycle = true;
                            return 0;
                        };
                    }
                } break;
                case 1: {
                    if (x == 9) Cycle = false; //�������� ���� �������� ����
                    else {  //���������� ������ �����
                        if (arr[x + 1][y] == 'T') {
                            arr[x + 1][y] = 'O';
                            Cycle = true;
                            return 5;
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
                }
            } while (Cycle);
        }
        else if (�oordinate_3_TTT == 2)//������ ������
        {
        bool Cycle = false;
        do {
            int �oordinate_3_2_TTT = rand() % 2; //��������� ��������� ���������� ���� ������ ���� �����
            switch (�oordinate_3_2_TTT) {
            case 0: {
                if (y == 8) Cycle = false; //�������� ���� �������� ����
                else {  //���������� ������ ������
                    if (arr[x][y + 2] == 'T') {
                        arr[x][y + 2] = 'O';
                        Cycle = true;
                        return 5;
                    }
                    else if (arr[x][y + 2] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x][y + 2] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 1: {
                if (y == 0) Cycle = false; //�������� ���� �������� ����
                else {  //���������� ������ �����
                    if (arr[x][y - 1] == 'T') {
                        arr[x][y - 1] = 'O';
                        Cycle = true;
                        return 5;
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
        } while (Cycle);
        }
        else if (�oordinate_3_TTT == 3)//������ ������
        {
        bool Cycle = false;
        do {
            int �oordinate_3_2_TTT = rand() % 2; //��������� ��������� ���������� ���� ������ ���� �����
            switch (�oordinate_3_2_TTT) {
            case 0: {
                if (x == 8) Cycle = false; //�������� ���� �������� ����
                else {  //���������� ������ �����
                    if (arr[x+2][y] == 'T') {
                        arr[x + 2][y] = 'O';
                        Cycle = true;
                        return 5;
                    }
                    else if (arr[x + 2][y] == '*') {
                        Cycle = false;
                    }
                    else {
                        arr[x + 2][y] = '*';
                        Cycle = true;
                        return 0;
                    };
                }
            } break;
            case 1: {
                if (x == 0) Cycle = false; //�������� ���� �������� ����
                else {  //���������� ������ ������
                    if (arr[x-1][y] == 'T') {
                        arr[x - 1][y] = 'O';
                        Cycle = true;
                        return 5;
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
            }
        } while (Cycle);
        }
        else if (�oordinate_3_TTT == 4)//����� ������
        {
        bool Cycle = false;
        do {
            int �oordinate_3_2_TTT = rand() % 2; //��������� ��������� ���������� ���� ������ ���� �����
            switch (�oordinate_3_2_TTT) {
            case 0: {
                if (y == 1) Cycle = false; //�������� ���� �������� ����
                else {  //���������� ������ �����
                    if (arr[x][y - 1] == 'T') {
                        arr[x][y - 1] = 'O';
                        Cycle = true;
                        return 5;
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
            case 1: {
                if (y == 9) Cycle = false; //�������� ���� �������� ����
                else {  //���������� ������ ������
                    if (arr[x][y + 1] == 'T') {
                        arr[x][y + 1] = 'O';
                        Cycle = true;
                        return 5;
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
            }
        } while (Cycle);
        }

    }
}


