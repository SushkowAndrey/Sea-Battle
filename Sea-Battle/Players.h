#pragma once
#include <iostream>

using namespace std;

// ��������� ���� �������
struct Igroki_2_na_2 {
    string Igrok_1;
    string Igrok_2;
    void Input() {
        cout << "���� ������ �� �������" << endl;
        cout << "������� ��� ������� ������ (����) "; cin >> Igrok_1;
        system("cls");
        cout << "���� ������ �� �������" << endl;
        cout << "������� ��� ������� ������ (����) "; cin >> Igrok_2;
    }
};