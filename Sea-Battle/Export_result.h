#pragma once
#include <fstream>

using namespace std;

void Export_Result(string Res) {

	ofstream File;
    try
    {
        File.open("Result.txt", ios::app);
        cout << "Результат сохранен в файл" << endl;
        File << Res << endl;
        File.close();

    }
    catch (...)
    {
        cout << "Ошибка сохранения в файл" << endl;
    }


}