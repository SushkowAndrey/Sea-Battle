#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ImportResult(string path) {

	ifstream File;

    try
    {
        File.open("Result.txt", ios::in);
        char Res;
        while (File.get(Res)) {
            cout << Res;
        }
        File.close();
    }
    catch (...)
    {
        cout << "Ошибка открытия файла" << endl;
    }
}
