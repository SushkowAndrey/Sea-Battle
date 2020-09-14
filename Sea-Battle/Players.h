#pragma once
#include <iostream>

using namespace std;

// структура двух игроков
struct Igroki_2_na_2 {
    string Igrok_1;
    string Igrok_2;
    void Input() {
        cout << "¬вод данных об игроках" << endl;
        cout << "¬ведите им€ первого игрока (англ) "; cin >> Igrok_1;
        system("cls");
        cout << "¬вод данных об игроках" << endl;
        cout << "¬ведите им€ второго игрока (англ) "; cin >> Igrok_2;
    }
};