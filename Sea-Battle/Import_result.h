#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ImportResult(string path) {

	ifstream File;

	File.open("Result.txt", ios::in);
    if (!File.is_open())
    {
        //TODO создание исключения
    }
    else
    {
        char Res;
        while (File.get(Res)) {
            cout << Res;
        }
    }
    File.close();

}
