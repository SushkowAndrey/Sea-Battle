#pragma once
#include <fstream>

using namespace std;

void Export_Result(string Res) {

	ofstream File;

	File.open("Result.txt", ios::app);

    if (!File.is_open())
    {
        //TODO �������� ����������
    }
    else
    {
        cout << "��������� �������� � ����" << endl;
        File << Res << endl;
        File.close();
    }

}