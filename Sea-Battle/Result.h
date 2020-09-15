#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Result_play {
	string Igrok;
	int Result_Hoda_1;
	int Result_Hoda_2;
};





void Res_play(Result_play Result) {
	cout << "Выиграл Игрок " + Result.Igrok + " со счетом " << Result.Result_Hoda_1 + " - " + Result.Result_Hoda_2 << endl;
}