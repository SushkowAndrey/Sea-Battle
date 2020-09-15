// морской бой-тестовый вариант в однопалубными кораблями
//Сделать разный размер поля на выбор игрока
// сделать повторный удар при попадании

#include <iostream>
#include <ctime>
#include <string>
#include "Function.h"
#include "Export_result.h"
#include "Import_result.h"
#include "Players.h"
#include "Result.h"

using namespace std;


int main()
{
    setlocale(0, "ru");
    srand(time(0));
    const int SIZE = 10;
    char arr3[11] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' }; //массив для обозначения нумерации ячеек
    bool PobedaI = false, PobedaKomp = false, Pobeda_I_1 = false, Pobeda_I_2 = false;
    bool Povtor_hoda = false;
    char Povtor_igry;
    int Tip_Igry;
    //процесс игры
    do {
        char Battle_Pole_I[SIZE][SIZE] = { {' ', ' ', ' '} };
        char Battle_Pole_I_1[SIZE][SIZE] = { {' ', ' ', ' '} };
        char Battle_Pole_I_2[SIZE][SIZE] = { {' ', ' ', ' '} };
        char Battle_Pole_Komp[SIZE][SIZE] = { {' ', ' ', ' '} };
        int Podbitye_Kor_I = 0; //количество подбитых кораблей на момент начала игры у игрока
        int Podbitye_Kor_Komp = 0; //количество подбитых кораблей на момент начала игры у игрока
        int Result_Hoda_I = 0; //переменная для подсчета результатов хода игрока (количества подбитых кораблей)
        int Result_Hoda_K = 0; //переменная для подсчета результатов хода компьютера (количества подбитых кораблей)
        int Result_Hoda_I2 = 0; //переменная для подсчета результатов хода игрока 2 (количества подбитых кораблей)
        cout << "       Добро пожаловать в игру Морской бой" << endl;
        cout << "                Выберите тип игры            " << endl;
        cout << "      1-Игра с компьютером  2-Игра с напарником            " << endl;
        cout << "            3-Посмотреть прошлый результат            " << endl;
        // цикл выбора количества игроков 
        do {
            cin >> Tip_Igry;
            if (Tip_Igry < 1 || Tip_Igry > 3)
                cout << "Некорректное значение, повторите ввод" << endl;
        } while (Tip_Igry != 1 && Tip_Igry != 2 && Tip_Igry != 3);
        system("cls");
        switch (Tip_Igry) {
            // игра с компьютером
        case 1:
        {
           //количество кораблей 4 (3 однопалубных, 1 двухпалубный)
            int Ship_Num=5, count = 0;
            bool Povtor_Udara = false;
            system("cls");
            //заполнение игрового поля-шаблон игрового поля
            cout << "Заполните игровое поле, выбрав необходимые координаты" << endl;
            Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
            cout << endl;
            for (int i = 0; i < SIZE; i++) {
                cout << "|" << i << "|";          //цикл для обозначения вертикальной строки координат
                for (int j = 0; j < SIZE; j++) {
                    cout << "| |";
                }
                cout << endl;
            }
            //расстановка кораблей игроком
            //расстановка однопалубных кораблей
            while (count < 3) {
                Rasstanovka_kor(Battle_Pole_I);
                system("cls");
                cout << "Поле игрока" << endl;
                //горизонтальная граница поля
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                //показ однопалубных кораблей
                Pokaz_Ship(Battle_Pole_I);
                count++;
            }
           //расстановка двухпалубных кораблей
           //расстановка первой палубы двухпалубного корабля
                Rasstanovka_kor_2_pal_1(Battle_Pole_I);
                system("cls");
                cout << "Поле игрока" << endl;
                //горизонтальная граница поля
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                Pokaz_Ship(Battle_Pole_I);
           //расстановка второй палубы двухпалубного корабля
                Rasstanovka_kor_2_pal_2(Battle_Pole_I);
                system("cls");
                cout << "Поле игрока" << endl;
                //горизонтальная граница поля
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                Pokaz_Ship(Battle_Pole_I);
            //расстановка кораблей компьютером
            while (count < Ship_Num) {
                Rasstanovka_kor_Komp(Battle_Pole_Komp);
                count++;
            }
            count = 1;
            // процесс боя
            do {
                //ход игрока
                cout << "Счет " << Result_Hoda_I << "/" << Ship_Num << " (Игрок) - (Компьютер) " << Result_Hoda_K << "/" << Ship_Num << endl;
                cout << "Игрок наносит " << count << " удар" << endl; // переменная count показывает число ударов
                do { //цикл для определения повторения хода
                    Povtor_hoda = HodIgr(Battle_Pole_Komp);
                    system("cls");
                    cout << "           Поле игрока                         Компьютера" << endl;
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    cout << "     ";
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    cout << endl;
                    Pokaz_Udar(Battle_Pole_Komp, Battle_Pole_I);
                    count++;
                    // подсчет количества подбитых кораблей компьютера для окончания хода
                    Result(Battle_Pole_Komp);
                    Result_Hoda_I = Result(Battle_Pole_Komp);
                    if (Result_Hoda_I == Ship_Num) {
                        break;
                    }
                    if (Povtor_hoda) { // уведомление о попадании и повторе хода
                        cout << "Корабль компьютера уничтожен. Нажмите 0, что бы повторить удар" << endl;
                        int Povt_I;
                        do {
                            cin >> Povt_I;
                            if (Povt_I != 0)
                                cout << "Некорректное значение, попробуйте еще раз" << endl;
                            else
                                break;
                        } while (Povt_I != 0);
                    }
                } while (Povtor_hoda);
                // подсчет количества подбитых кораблей компьютера для окончания боя
                if (Result_Hoda_I == Ship_Num) {
                    PobedaI = true;
                    break;
                }
                //ход компьютера
                do {
                    cout << "Счет " << Result_Hoda_I << "/" << Ship_Num << " (Игрок) - (Компьютер) " << Result_Hoda_K << "/" << Ship_Num << endl;
                    cout << "Компьютер наносит " << count << " удар" << endl; // переменная count показывает число ударов
                    cout << "Нажмите 0, что бы компьютер ударил" << endl;
                    int Udar;
                    do {
                        cin >> Udar;
                        if (Udar != 0)
                            cout << "Некорректное значение, попробуйте еще раз" << endl;
                        else
                            break;
                    } while (Udar != 0);
                    Povtor_hoda = HodKomp(Battle_Pole_I);
                    system("cls");
                    cout << "           Поле игрока                         Компьютера" << endl;
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    cout << "     ";
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    cout << endl;
                    Pokaz_Udar(Battle_Pole_Komp, Battle_Pole_I);
                    count++;
                    // подсчет количества подбитых кораблей игрока для окончания хода
                    Result_Hoda_K = Result(Battle_Pole_I);
                    if (Result_Hoda_K == Ship_Num) {
                        break;
                    }
                    if (Povtor_hoda) {  // уведомление о попадании и повторе хода
                        cout << "Ваш корабль уничтожен. Нажмите 0, что бы компьютер повторил удар" << endl;
                        int Povt_K;
                        do {
                            cin >> Povt_K;
                            if (Povt_K != 0)
                                cout << "Некорректное значение, попробуйте еще раз" << endl;
                            else
                                break;
                        } while (Povt_K != 0);
                    }
                } while (Povtor_hoda);
                // подсчет количества подбитых кораблей игрока для окончания боя
                if (Result_Hoda_K == Ship_Num) {
                    PobedaKomp = true;
                    break;
                }
            } while (!PobedaI && !PobedaKomp);
            //результат игры
            if (PobedaI) {
                cout << "Выиграл Игрок! УРА!!!" << endl;
            }
            else if (PobedaKomp) {
                cout << "Выиграл Компьютер! УРА!!!" << endl;
            }
        }
        break;
        //ИГРА СО ВТОРЫМ ИГРОКОМ
        case 2:
        {
            bool Povtor_Udara = false;
            int count = 0;
            int Ship_Num;
            //Ввод данных об игроках
            Igroki_2_na_2 Igroki; //выбор игроков из структуры
            Igroki.Input();
            system("cls");
            //цикл выбора количества кораблей
            cout << "      Далее необходимо заполнить игровое поле" << endl;
            cout << "Выберите количество однопалубных кораблей, но не более 5" << endl;
            do {
                cin >> Ship_Num;
                if (Ship_Num > 5 || Ship_Num < 1)
                    cout << "Некорректное значение, повторите ввод" << endl;
            } while (Ship_Num > 5 || Ship_Num < 1);
            system("cls");
            //заполнение игрового поля-шаблон игрового поля
            cout << "Теперь заполните игровое поле, выбрав необходимые координаты" << endl;
            cout << "Поле заполняет " << Igroki.Igrok_1 << endl;
            cout << "Игроку " << Igroki.Igrok_2 << " необходимо отвернуться" << endl;
            //пустой шаблон игрового поля
            Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
            cout << endl;
            for (int i = 0; i < SIZE; i++) {
                cout << "|" << i << "|";          //цикл для обозначения вертикальной строки координат
                for (int j = 0; j < SIZE; j++) {
                    cout << "| |";
                }
                cout << endl;
            }
            //расстановка кораблей первым игроком  
            while (count < Ship_Num) {
                Rasstanovka_kor(Battle_Pole_I_1);
                system("cls");
                cout << "Поле игрока " << Igroki.Igrok_1 << endl;
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                //заполненное поле первого игрока
                Pokaz_Ship(Battle_Pole_I_1);
                count++;
            }
            count = 0;
            cout << "Теперь нажмите 0 для заполнения поля игроком " << Igroki.Igrok_2 << endl;
            int Peredacha_Hoda;
            do {
                cin >> Peredacha_Hoda;
                if (Peredacha_Hoda != 0)
                    cout << "Некорректное значение, попробуйте еще раз" << endl;
                else
                    break;
            } while (Peredacha_Hoda != 0);
            system("cls");
            cout << "Поле заполняет " << Igroki.Igrok_2 << endl;
            cout << "Игроку " << Igroki.Igrok_1 << " необходимо отвернуться" << endl;
            //пустой шаблон игрового поля
            Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
            cout << endl;
            for (int i = 0; i < SIZE; i++) {
                cout << "|" << i << "|";          //цикл для обозначения вертикальной строки координат
                for (int j = 0; j < SIZE; j++) {
                    cout << "| |";
                }
                cout << endl;
            }
            //расстановка кораблей вторым игроком  
            while (count < Ship_Num) {
                Rasstanovka_kor_2(Battle_Pole_I_2);
                system("cls");
                cout << "Поле игрока " << Igroki.Igrok_2 << endl;
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                //заполненное поле второго игрока
                Pokaz_Ship(Battle_Pole_I_2);
                count++;
            }
            cout << "Теперь нажмите 0 для начала игры" << endl;
            int Nachalo_Igry;
            do {
                cin >> Nachalo_Igry;
                if (Nachalo_Igry != 0)
                    cout << "Некорректное значение, попробуйте еще раз" << endl;
                else
                    break;
            } while (Nachalo_Igry != 0);
            system("cls");
            // процесс боя
            count = 1;
            do {
                //ход первого игрока
                cout << "Счет " << Result_Hoda_I << "/" << Ship_Num << " (Игрок "<< Igroki.Igrok_1 << ")"<< "-(Игрок "<< Igroki.Igrok_2 << ") " << Result_Hoda_I2 << "/" << Ship_Num << endl;
                cout << "Игрок " << Igroki.Igrok_1 << " наносит " << count << " удар" << endl;
                do { //цикл для определения повторения хода
                    Povtor_hoda = HodIgr_1(Battle_Pole_I_2);
                    system("cls");
                    cout << " Поле игроков " << Igroki.Igrok_1 << "                                     " << Igroki.Igrok_2 << endl;
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    cout << "     ";
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    cout << endl;
                    Pokaz_Udar_2(Battle_Pole_I_1, Battle_Pole_I_2); // показ двух полей игроков только с результатами хода
                    count++;
                    // подсчет количества подбитых кораблей компьютера для завершения хода
                    Result(Battle_Pole_I_2);
                    Result_Hoda_I = Result(Battle_Pole_I_2);
                    if (Result_Hoda_I == Ship_Num) {
                        break;
                    }
                    if (Povtor_hoda) { // уведомление о попадании и повторе хода
                        cout << "Корабль игрока " << Igroki.Igrok_2 << " уничтожен. Нажмите 0, что бы повторить удар" << endl;
                        int Povt_I;
                        do {
                            cin >> Povt_I;
                            if (Povt_I != 0)
                                cout << "Некорректное значение, попробуйте еще раз" << endl;
                            else
                                break;
                        } while (Povt_I != 0);
                    }
                } while (Povtor_hoda);
                // подсчет количества подбитых кораблей второго игрока для завершения боя
                if (Result_Hoda_I == Ship_Num) {
                    Pobeda_I_1 = true;
                    break;
                }
                //ход второго игрока
                cout << "Счет " << Result_Hoda_I << "/" << Ship_Num << " (Игрок " << Igroki.Igrok_1 << ")" << "-(Игрок " << Igroki.Igrok_2 << ") " << Result_Hoda_I2 << "/" << Ship_Num << endl;
                cout << "Игрок " << Igroki.Igrok_2 << " наносит " << count << " удар" << endl;
                do { //цикл для определения повторения хода
                    Povtor_hoda = HodIgr_2(Battle_Pole_I_1);
                    system("cls");
                    cout << " Поле игроков " << Igroki.Igrok_1 << "                                     " << Igroki.Igrok_2 << endl;
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    cout << "     ";
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    cout << endl;
                    Pokaz_Udar_2(Battle_Pole_I_1, Battle_Pole_I_2); // показ двух полей игроков только с результатами хода
                    count++;
                    // подсчет количества подбитых кораблей компьютера для завершения хода
                    Result(Battle_Pole_I_1);
                    Result_Hoda_I2 = Result(Battle_Pole_I_1);
                    if (Result_Hoda_I2 == Ship_Num) {
                        break;
                    }
                    if (Povtor_hoda) { // уведомление о попадании и повторе хода
                        cout << "Корабль игрока " << Igroki.Igrok_1 << " уничтожен. Нажмите 0, что бы повторить удар" << endl;
                        int Povt_I;
                        do {
                            cin >> Povt_I;
                            if (Povt_I != 0)
                                cout << "Некорректное значение, попробуйте еще раз" << endl;
                            else
                                break;
                        } while (Povt_I != 0);
                    }
                } while (Povtor_hoda);
                // подсчет количества подбитых кораблей компьютера для завершения боя
                if (Result_Hoda_I2 == Ship_Num) {
                    Pobeda_I_2 = true;
                    break;
                }
            } while (!Pobeda_I_1 && !Pobeda_I_2);
            //результат игры
            if (Pobeda_I_1) {
                cout << "Выиграл Игрок " << Igroki.Igrok_1 << " со счетом "<< Result_Hoda_I << " - " << Result_Hoda_I2 << endl;
                //////////////////////////////////////////////////////////
                //Result_play(Igroki.Igrok_1, Result_Hoda_I, Result_Hoda_I2);
                //выгрузка результата игры в файл
                cout << "Выгрузить результат в файл?" << endl;
                cout << "       Y/N      " << endl;
                char Vygruzka;
                do {
                    cin >> Vygruzka;
                    system("cls");
                    if (Vygruzka != 'Y'&& Vygruzka != 'N')
                        cout << "Некорректное значение, попробуйте еще раз" << endl;
                    else
                        break;
                } while (Vygruzka != 'Y' && Vygruzka != 'N');
                if (Vygruzka == 'Y') {
                    //Export_Result(Result_play(Igroki.Igrok_1, Result_Hoda_I, Result_Hoda_I2));
                    break;
                }
                else if (Vygruzka == 'N')
                    break;
            }
            else if (Pobeda_I_2) {
                cout << "Выиграл Игрок " << Igroki.Igrok_2 << " со счетом " << Result_Hoda_I << " - " << Result_Hoda_I2 << endl;
                string Res2 = Igroki.Igrok_2;
                cout << "Выгрузить результат в файл?" << endl;
                cout << "       Y/N      " << endl;
                char Vygruzka;
                do {
                    cin >> Vygruzka;
                    system("cls");
                    if (Vygruzka != 'Y' && Vygruzka != 'N')
                        cout << "Некорректное значение, попробуйте еще раз" << endl;
                    else
                        break;
                } while (Vygruzka != 'Y' && Vygruzka != 'N');
                if (Vygruzka == 'Y') {
                    Export_Result(Res2);
                    break;
                }
                else if (Vygruzka == 'N')
                    break;
            }
        }
        break;
        case 3:
        {
            cout << "Результаты прошлых игр" << endl;
            ImportResult("Result.txt");
        }
        break;
        }
        cout << "Хотите повторить" << endl;
        cout << "       Y/N      " << endl;
        cin >> Povtor_igry;
        do {
            if (Povtor_igry != 'Y')
                cout << "Некорректное значение, попробуйте еще раз" << endl;
            else if (Povtor_igry != 'N')
                break;
        } while (Povtor_igry != 'Y'&& Povtor_igry != 'N');
        system("cls");
    } while (Povtor_igry == 'Y');
    system("pause");
}

