#pragma once
#include <fstream>

using namespace std;

void Export_Result(string Res) {

	ofstream File;
    try
    {
        File.open("Result.txt", ios::app);
        cout << "��������� �������� � ����" << endl;
        File << Res << endl;
        File.close();

    }
    catch (...)
    {
        cout << "������ ���������� � ����" << endl;
    }


}