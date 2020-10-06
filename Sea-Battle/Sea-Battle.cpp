// морской бой-тестовый вариант в однопалубными кораблями
//Сделать разный размер поля на выбор игрока
// сделать повторный удар при попадании

#include <iostream>
#include <ctime>
#include <string>
#include "Function_Igr1_and_Igr2.h"
#include "Export_result.h"
#include "Import_result.h"
#include "Players.h"
#include "The_alignment_of_the_ships_I_K.h"
#include "Сonducting_a_battle_I_K.h"

using namespace std;

int main()
{
    setlocale(0, "ru");
    srand(time(0));
    const int SIZE = 10; //размер поля
    char arr3[11] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' }; //массив для обозначения нумерации ячеек
    bool PobedaI = false, PobedaKomp = false, Pobeda_I_1 = false, Pobeda_I_2 = false;
    int Povtor_hoda_Igr_Komp;//переменная для определения повтора хода игрока/компьютера
    bool Povtor_hoda = false;//переменная для определения повтора хода двух игроков
    bool Wound_DD=false, Wound_GG = false, Wound_RR = false; //ранил компьютер корабль DD, GG или RR игрока , изначально присвоено нулевое значение
    bool Wound_TTT = false; //ранил компьютер корабль TTT игрока , изначально присвоено нулевое значение
    int Paluba_2_I_DD = 0, Paluba_2_I_GG = 0, Paluba_2_I_RR = 0; //переменная для расчета количества подбитых палуб первого двухпалубного корабля игрока
    int Paluba_3_I_TTT = 0;//переменная для расчета количества подбитых палуб первого трехпалубного корабля игрока
    int Paluba_2_K_DD = 0, Paluba_2_K_GG = 0, Paluba_2_K_RR = 0; //переменная для расчета количества подбитых палуб первого двухпалубного корабля компьютера
    int Paluba_3_K_TTT = 0;//переменная для расчета количества подбитых палуб треххпалубного корабля компьютера
    int X = 0, Y = 0; //переменные для записи координат удара компьютером
    int Enumeration_3_TTT = 0; // переменная для записи выбора компьютера при первом попадании в трехпалубный корабль игрока
    char Povtor_igry; //переменная для определения повтора игры по ее окончанию
    string Game_Step;    //переменная для определения корректности ввода символа при выборе
    //процесс игры
    do {
        //массивы игровых полей
        char Battle_Pole_I[SIZE][SIZE] = { {' ', ' ', ' '} };
        char Battle_Pole_I_1[SIZE][SIZE] = { {' ', ' ', ' '} };
        char Battle_Pole_I_2[SIZE][SIZE] = { {' ', ' ', ' '} };
        char Battle_Pole_Komp[SIZE][SIZE] = { {' ', ' ', ' '} };
        int Podbitye_Kor_I = 0; //количество подбитых кораблей на момент начала игры у игрока
        int Podbitye_Kor_Komp = 0; //количество подбитых кораблей на момент начала игры у компьютера
        int Result_Hoda_I = 0; //переменная для подсчета результатов хода игрока (количества подбитых кораблей)
        int Result_Hoda_K = 0; //переменная для подсчета результатов хода компьютера (количества подбитых кораблей)
        int Result_Hoda_I2 = 0; //переменная для подсчета результатов хода игрока 2 (количества подбитых кораблей)
        cout << "       Добро пожаловать в игру Морской бой" << endl;
        cout << "                Выберите тип игры            " << endl;
        cout << "      1-Игра с компьютером  2-Игра с напарником            " << endl;
        cout << "            3-Посмотреть прошлый результат            " << endl;
        // цикл выбора количества игроков 
        // главное меню
        //проверка на дурака
        int Tip_Igry = Proverka_vvoda(Game_Step, 0);
        system("cls");
        switch (Tip_Igry) {
            // игра с компьютером
        case 1:
        {
           //количество кораблей 4 (4 однопалубных, 3 двухпалубных, 1 трехпалубный)
            int Ship_Num=13, //8 палуб всего (4*1+3*2+1*3)
            count = 0; //count - счетчик для работы циклов
            //переменная для определения повтора удара
            system("cls");
            // выбор способа заполнения поля игрока
            cout << " Выберите способ заполнения вашего поля  " << endl;
            cout << "      1-Вручную  2-Автоматически            " << endl;
            int Method_of_filling_in_the_field = Proverka_vvoda(Game_Step, 0);//дополнить два выбора вариантов
            switch (Method_of_filling_in_the_field) {
                //заполнение игрового поля вручную
            case 1:
            {
                system("cls");
                //шаблон игрового поля
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
                while (count < 4) {
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
                //расстановка первого двухпалубного кораблей 
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
                //расстановка второго двухпалубного кораблей 
                //расстановка первой палубы двухпалубного корабля
                Rasstanovka_kor_2_2_pal_1(Battle_Pole_I);
                system("cls");
                cout << "Поле игрока" << endl;
                //горизонтальная граница поля
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                Pokaz_Ship(Battle_Pole_I);
                //расстановка второй палубы второго двухпалубного корабля
                Rasstanovka_kor_2_2_pal_2(Battle_Pole_I);
                system("cls");
                cout << "Поле игрока" << endl;
                //горизонтальная граница поля
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                Pokaz_Ship(Battle_Pole_I);
                //расстановка третьего двухпалубного кораблей 
                //расстановка первой палубы двухпалубного корабля
                Rasstanovka_kor_2_3_pal_1(Battle_Pole_I);
                system("cls");
                cout << "Поле игрока" << endl;
                //горизонтальная граница поля
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                Pokaz_Ship(Battle_Pole_I);
                //расстановка второй палубы второго двухпалубного корабля
                Rasstanovka_kor_2_3_pal_2(Battle_Pole_I);
                system("cls");
                cout << "Поле игрока" << endl;
                //горизонтальная граница поля
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                Pokaz_Ship(Battle_Pole_I);
                //расстановка первого трехпалубного кораблей 
                //расстановка первой палубы трехпалубного корабля
                Rasstanovka_kor_3_pal_1(Battle_Pole_I);
                system("cls");
                cout << "Поле игрока" << endl;
                //горизонтальная граница поля
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                Pokaz_Ship(Battle_Pole_I);
                //расстановка второй палубы трехпалубного корабля
                Rasstanovka_kor_3_pal_2(Battle_Pole_I);
                system("cls");
                cout << "Поле игрока" << endl;
                //горизонтальная граница поля
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                Pokaz_Ship(Battle_Pole_I);
                //расстановка третьей палубы трехпалубного корабля
                Rasstanovka_kor_3_pal_3(Battle_Pole_I);
                system("cls");
                cout << "Поле игрока" << endl;
                //горизонтальная граница поля
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                Pokaz_Ship(Battle_Pole_I);


            } break;
            //заполнение игрового поля автоматически
            /////////////////ЗАПОЛНЯЕТСЯ, НО НЕ ИСПОЛЬЗУЕТСЯ В ДАЛЬНЕЙШЕМ
            case 2: 
            {
                char Battle_Pole_I_auto[SIZE][SIZE];
                //цикл для перебора различных вариантов расположения кораблей
                int Confirmation_of_the_choice; //переменная для определении выбора расположения кораблей при автоматическом заполнении поля игрока
                do
                {
                    // новый массив, который после окончания выбора порядка расположения кораблей приравнивается к первоначальному
                    char Battle_Pole_I[SIZE][SIZE] = { };
                    system("cls");
                    //расстановка кораблей автоматически
                    //шаблон игрового поля
                    cout << "Выберите игровое поле" << endl;
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    //расстановка однопалубных кораблей
                    count = 0;
                    while (count < 4) {
                        Rasstanovka_kor_Komp(Battle_Pole_I);
                        count++;
                    }
                    //расстановка двухпалубных кораблей 
                    Rasstanovka_kor_2_pal_1_Komp(Battle_Pole_I);
                    Rasstanovka_kor_2_pal_2_Komp(Battle_Pole_I);
                    Rasstanovka_kor_2_2_pal_1_Komp(Battle_Pole_I);
                    Rasstanovka_kor_2_2_pal_2_Komp(Battle_Pole_I);
                    Rasstanovka_kor_2_3_pal_1_Komp(Battle_Pole_I);
                    Rasstanovka_kor_2_3_pal_2_Komp(Battle_Pole_I);
                    Rasstanovka_kor_3_pal_1_Komp(Battle_Pole_I);
                    Rasstanovka_kor_3_pal_2_Komp(Battle_Pole_I);
                    Rasstanovka_kor_3_pal_3_Komp(Battle_Pole_I);
                    cout << endl;
                    Pokaz_Ship(Battle_Pole_I);
                    cout <<"Если хотите поменять поле нажмите любую кнопку, если поле устраивает нажмите 0"<< endl;
                    cin >> Confirmation_of_the_choice;
                    if (Confirmation_of_the_choice == 0) {
                        Battle_Pole_I[SIZE][SIZE] = Battle_Pole_I_auto[SIZE][SIZE];
                    }
                    system("cls");
                } while (Confirmation_of_the_choice != 0);
            } break;
            }
            //расстановка кораблей компьютером
                //расстановка однопалубных кораблей
                count = 0;
                   while (count < 4) {
                    Rasstanovka_kor_Komp(Battle_Pole_Komp);
                    count++;
                }
            //расстановка двухпалубных кораблей 
            //расстановка первой и второй палубы двухпалубного корабля
          
            Rasstanovka_kor_2_pal_1_Komp(Battle_Pole_Komp);
            Rasstanovka_kor_2_pal_2_Komp(Battle_Pole_Komp);
            Rasstanovka_kor_2_2_pal_1_Komp(Battle_Pole_Komp);
            Rasstanovka_kor_2_2_pal_2_Komp(Battle_Pole_Komp);
            Rasstanovka_kor_2_3_pal_1_Komp(Battle_Pole_Komp);
            Rasstanovka_kor_2_3_pal_2_Komp(Battle_Pole_Komp);
            Rasstanovka_kor_3_pal_1_Komp(Battle_Pole_Komp);
            Rasstanovka_kor_3_pal_2_Komp(Battle_Pole_Komp);
            Rasstanovka_kor_3_pal_3_Komp(Battle_Pole_Komp);
            cout << "Поле компьютера" << endl;
            Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
            cout << endl;
            Pokaz_Ship(Battle_Pole_Komp); //показ поля компьютера (если необходимо, в идеале мы не видим корабли компьютера)
            count = 1; //переменная считает номер удара, начинается с первого (1)
            ////////////////////////////////// процесс боя игрока и компьютера /////////////////////////////////////
            do {
                //ход игрока
                cout << "Координата Х " << X << "; координата Y " << Y << "; Булева DD " << Wound_DD << "; Булева GG " << Wound_GG << "; Булева RR " << Wound_RR << endl;
                cout << "Выбор компьютером чистал при попадании в трехпалубный корабль " << Enumeration_3_TTT << endl;
                cout << "Счет " << Result_Hoda_I << "/" << Ship_Num << " (Игрок) - (Компьютер) " << Result_Hoda_K << "/" << Ship_Num << endl;
                cout << "Игрок наносит " << count << " удар" << endl; // переменная count показывает число ударов
                do { //цикл для определения повторения хода
                    Povtor_hoda_Igr_Komp = HodIgr(Battle_Pole_Komp);
                    system("cls");
                    cout << "           Поле игрока                         Компьютера" << endl;
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    cout << "     ";
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    cout << endl;
                    Pokaz_Udar(Battle_Pole_Komp, Battle_Pole_I);
                    count++;
                    //цикл для проверки попадания
                    switch (Povtor_hoda_Igr_Komp)
                    {
                    case 0: //если нет попадания
                    {
                        cout << "Мимо" << endl;
                    }
                    break;
                    case 1: //если уничтожен однопалубный корабль
                    {
                        cout << "Корабль компьютера уничтожен. Повторите удар" << endl;
                    }
                    break;
                    case 2: //если есть попадание в двухпалубный корабль DD
                    {
                        Paluba_2_I_DD++; //при попадании увеличиваем количество подпитых палуб первого двухпалубного корабля
                        if (Paluba_2_I_DD ==2)
                            cout << "Корабль компьютера уничтожен. Повторите удар" << endl;
                        else
                        cout << "Ранен. Повторите удар" << endl;  
                    }
                    break;
                    case 3: //если есть попадание в двухпалубный корабль GG
                    {
                        Paluba_2_I_GG++; //при попадании увеличиваем количество подпитых палуб первого двухпалубного корабля
                        if (Paluba_2_I_GG == 2)
                            cout << "Корабль компьютера уничтожен. Повторите удар" << endl;
                        else
                            cout << "Ранен. Повторите удар" << endl;
                    }
                    break;
                    case 4: //если есть попадание в двухпалубный корабль RR
                    {
                        Paluba_2_I_RR++; //при попадании увеличиваем количество подпитых палуб первого двухпалубного корабля
                        if (Paluba_2_I_RR == 2)
                            cout << "Корабль компьютера уничтожен. Повторите удар" << endl;
                        else
                            cout << "Ранен. Повторите удар" << endl;
                    }
                    break;
                    case 5: //если есть попадание в трехпалубный корабль TTT
                    {
                        Paluba_3_I_TTT++; //при попадании увеличиваем количество подпитых палуб трехпалубного корабля
                        if (Paluba_3_I_TTT == 3)
                            cout << "Корабль компьютера уничтожен. Повторите удар" << endl;
                        else
                            cout << "Ранен. Повторите удар" << endl;
                    }
                    break;
                    }
                    // подсчет количества подбитых кораблей компьютера для окончания хода
                    Result_Hoda_I = Result(Battle_Pole_Komp);
                    if (Result_Hoda_I == Ship_Num) {
                        break;
                    }
                } while (Povtor_hoda_Igr_Komp!=0);
                // подсчет количества подбитых кораблей компьютера для окончания боя
                if (Result_Hoda_I == Ship_Num) {
                    PobedaI = true;
                    break;
                }
                //ход компьютера///////////////////////////////////////////////////
                do {
                    //временные переменные для проверки 
                    Povtor_hoda_Igr_Komp = HodKomp(Battle_Pole_I, X, Y, Wound_DD, Wound_GG, Wound_RR, Wound_TTT, Enumeration_3_TTT);
                    system("cls");
                    cout << "           Поле игрока                         Компьютера" << endl;
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    cout << "     ";
                    Gor_Granica(arr3, SIZE);//цикл для обозначения горизонтальной строки координат
                    cout << endl;
                    Pokaz_Udar(Battle_Pole_Komp, Battle_Pole_I);
                    count++;
                    //цикл для проверки попадания
                    switch (Povtor_hoda_Igr_Komp)
                    {
                    case 0: //если нет попадания
                    {
                        cout << "Компьютер промахнулся. Наносите удар" << endl;
                    }
                    break;
                    case 1: //если уничтожен однопалубный корабль
                    {
                        cout << "Ваш корабль уничтожен. Нажмите 0, что бы продолжить" << endl;
                        int Povt_K;
                        //проверка на дурака при продолжении хода
                        do {
                            Povt_K = Proverka_vvoda(Game_Step, 2);
                        } while (Povt_K != 0);
                    }
                    break;
                    case 2: //если есть попадание в двухпалубный корабль DD
                    {
                        Paluba_2_K_DD++; //при попадании увеличиваем количество подпитых палуб первого двухпалубного корабля
                        if (Paluba_2_K_DD == 1) {
                            Wound_DD = true;
                            cout << "Ваш корабль ранен. Нажмите 0, что бы продолжить" << endl;
                            int Povt_K;
                            //проверка на дурака при продолжении хода
                            do {
                                Povt_K = Proverka_vvoda(Game_Step, 2);
                            } while (Povt_K != 0);
                        }
                        else {
                            Wound_DD = false;
                            cout << "Ваш корабль уничтожен. Нажмите 0, что бы продолжить" << endl;
                            int Povt_K;
                            //проверка на дурака при продолжении хода
                            do {
                                Povt_K = Proverka_vvoda(Game_Step, 2);
                            } while (Povt_K != 0);
                        }
                    }
                    break;
                    case 3: //если есть попадание в двухпалубный корабль GG
                    {
                        Paluba_2_K_GG++; //при попадании увеличиваем количество подпитых палуб первого двухпалубного корабля
                        if (Paluba_2_K_GG == 1) {
                            Wound_GG = true;
                            cout << "Ваш корабль ранен. Нажмите 0, что бы продолжить" << endl;
                            int Povt_K;
                            //проверка на дурака при продолжении хода
                            do {
                                Povt_K = Proverka_vvoda(Game_Step, 2);
                            } while (Povt_K != 0);
                        }
                        else {
                            Wound_GG = false;
                            cout << "Ваш корабль уничтожен. Нажмите 0, что бы продолжить" << endl;
                            int Povt_K;
                            //проверка на дурака при продолжении хода
                            do {
                                Povt_K = Proverka_vvoda(Game_Step, 2);
                            } while (Povt_K != 0);
                        }
                    }
                    break;
                    case 4: //если есть попадание в двухпалубный корабль RR
                    {
                        Paluba_2_K_RR++; //при попадании увеличиваем количество подпитых палуб первого двухпалубного корабля
                        if (Paluba_2_K_RR == 1) {
                            Wound_RR = true;
                            cout << "Ваш корабль ранен. Нажмите 0, что бы продолжить" << endl;
                            int Povt_K;
                            //проверка на дурака при продолжении хода
                            do {
                                Povt_K = Proverka_vvoda(Game_Step, 2);
                            } while (Povt_K != 0);
                        }
                        else {
                            Wound_RR = false;

                            cout << "Ваш корабль уничтожен. Нажмите 0, что бы продолжить" << endl;
                            int Povt_K;
                            //проверка на дурака при продолжении хода
                            do {
                                Povt_K = Proverka_vvoda(Game_Step, 2);
                            } while (Povt_K != 0);
                        }
                    }
                    break;
                    case 5: //если есть попадание в трехпалубный корабль TTT
                    {
                        Paluba_3_K_TTT++; //при попадании увеличиваем количество подпитых палуб первого двухпалубного корабля
                        if (Paluba_3_K_TTT != 3) {
                            Wound_TTT = true;
                            cout << "Ваш корабль ранен. Нажмите 0, что бы продолжить" << endl;
                            int Povt_K;
                            //проверка на дурака при продолжении хода
                            do {
                                Povt_K = Proverka_vvoda(Game_Step, 2);
                            } while (Povt_K != 0);
                        }
                        else {
                            Wound_TTT = false;
                            Enumeration_3_TTT = 0;
                            cout << "Ваш корабль уничтожен. Нажмите 0, что бы продолжить" << endl;
                            int Povt_K;
                            //проверка на дурака при продолжении хода
                            do {
                                Povt_K = Proverka_vvoda(Game_Step, 2);
                            } while (Povt_K != 0);
                        }
                    }
                    break;
                    }
                } while (Povtor_hoda_Igr_Komp != 0);
                // подсчет количества подбитых кораблей игрока для окончания хода
                Result_Hoda_K = Result(Battle_Pole_I);
                if (Result_Hoda_K == Ship_Num) {
                    PobedaKomp = true;
                    break;
                }
            } while (!PobedaI && !PobedaKomp);
            //результат игры
            if (PobedaI) {
                cout << "Выиграл Игрок со счетом " << Result_Hoda_I << " - " << Result_Hoda_K << endl;
                //переменная (строка) для записи результатов игры
                string Res1 = "Выиграл Игрок в бою с компьютером со счетом " + to_string(Result_Hoda_I) + " - " + to_string(Result_Hoda_K);
                //выгрузка результата игры в файл
                cout << "Выгрузить результат в файл?" << endl;
                cout << "       Y/N      " << endl;
                char Vygruzka;
                do {
                    Vygruzka = Proverka_vvoda(Game_Step, 1);
                } while (Vygruzka != 'Y' && Vygruzka != 'N');
                if (Vygruzka == 'Y') {
                    Export_Result(Res1);
                    break;
                }
                else if (Vygruzka == 'N')
                    break;
            }
            else if (PobedaKomp) {
                cout << "Выиграл Компьютер со счетом " << Result_Hoda_K << " - " << Result_Hoda_I << endl;
                //переменная (строка) для записи результатов игры
                string Res2 = "Выиграл Компьютер в бою с игроком со счетом " + to_string(Result_Hoda_K) + " - " + to_string(Result_Hoda_I);
                //выгрузка результата игры в файл
                cout << "Выгрузить результат в файл?" << endl;
                cout << "       Y/N      " << endl;
                char Vygruzka;
                do {
                    Vygruzka = Proverka_vvoda(Game_Step, 1);
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

        //////////////////////////////////////////////ИГРА СО ВТОРЫМ ИГРОКОМ///////////////////////////////////////////////////////
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
                string Res1 = "Выиграл Игрок " + Igroki.Igrok_1 + " со счетом " + to_string(Result_Hoda_I) + " - " + to_string(Result_Hoda_I2);
                //выгрузка результата игры в файл
                cout << "Выгрузить результат в файл?" << endl;
                cout << "       Y/N      " << endl;
                char Vygruzka;
                do {
                    Vygruzka = Proverka_vvoda(Game_Step, 1);
                } while (Vygruzka != 'Y' && Vygruzka != 'N');
                if (Vygruzka == 'Y') {
                    Export_Result(Res1);
                    break;
                }
                else if (Vygruzka == 'N')
                    break;
            }
            else if (Pobeda_I_2) {
                cout << "Выиграл Игрок " << Igroki.Igrok_2 << " со счетом " << Result_Hoda_I << " - " << Result_Hoda_I2 << endl;
                //выгрузка результата игры в файл
                string Res2 = "Выиграл Игрок " + Igroki.Igrok_2 + " со счетом " + to_string(Result_Hoda_I2)+ " - " + to_string(Result_Hoda_I);
                cout << "Выгрузить результат в файл?" << endl;
                cout << "       Y/N      " << endl;
                char Vygruzka;
                do {
                    Vygruzka = Proverka_vvoda(Game_Step, 1);
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
        //проверка на дурака при выходе из игры
        Povtor_igry = Proverka_vvoda(Game_Step, 1);
        system("cls");
    } while (Povtor_igry == 'Y');
    system("pause");
}

