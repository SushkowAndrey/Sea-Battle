// морской бой-тестовый вариант в однопалубными кораблями
//Сделать разный размер поля на выбор игрока
// сделать повторный удар при попадании

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int SIZE = 10;

//функция замены буквенного значения координаты столбца на цифру
int Zamena_B_na_Num(char Koord);
//функция расстановки кораблей первого игрока
void Rasstanovka_kor(char arr[SIZE][SIZE]);
//функция расстановки кораблей второго
void Rasstanovka_kor_2(char arr[SIZE][SIZE]);
// функция горизонтальной граници координат
void Gor_Granica(char* arr, int size);
//функция показа кораблей
void Pokaz_Ship(char arr[SIZE][SIZE]);
//функция расстановки кораблей компьютера
void Rasstanovka_kor_Komp(char arr[SIZE][SIZE]);
//функция хода игрока против компьютера
bool HodIgr(char arr[SIZE][SIZE]);
//функция хода первого игрока
bool HodIgr_1(char arr[SIZE][SIZE]);
//функция хода второго игрока
bool HodIgr_2(char arr[SIZE][SIZE]);
//функция отображения результатов хода (подбитые корабли и промахи игрока и компьютера)
void Pokaz_Udar(char arr1[SIZE][SIZE], char arr2[SIZE][SIZE]);
//функция отображения результатов хода (подбитые корабли и промахи компьютера)
bool HodKomp(char arr[SIZE][SIZE]);
//функция подсчета количества подбитых кораблей
int Result(char arr[SIZE][SIZE]);
//функция отображения результатов хода двух игроков (подбитые корабли и промахи первого и второго игрока)
void Pokaz_Udar_2(char arr1[SIZE][SIZE], char arr2[SIZE][SIZE]);

// структура двух игроков
struct Igroki_2_na_2 {
    string Igrok_1;
    string Igrok_2;
    void Input() {
        cout << "Ввод данных об игроках" << endl;
        cout << "Введите имя первого игрока (англ) "; cin >> Igrok_1;
        system("cls");
        cout << "Ввод данных об игроках" << endl;
        cout << "Введите имя второго игрока (англ) "; cin >> Igrok_2;
    }
};

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
        // цикл выбора количества игроков 
        do {
            cin >> Tip_Igry;
            if (Tip_Igry < 1 || Tip_Igry > 2)
                cout << "Некорректное значение, повторите ввод" << endl;
        } while (Tip_Igry != 1 && Tip_Igry != 2);
        system("cls");
        switch (Tip_Igry) {
            // игра с компьютером
        case 1:
        {
            cout << "      Для начала необходимо заполнить игровое поле" << endl;
            cout << "Выберите количество обнопалубных кораблей, но не более 5" << endl;
            // выбираем количество кораблей
            int Ship_Num, count = 0;
            bool Povtor_Udara = false;
            //цикл выбора количества кораблей
            do {
                cin >> Ship_Num;
                if (Ship_Num > 5)
                    cout << "Некорректное значение, повторите ввод" << endl;
            } while (Ship_Num > 5);
            system("cls");
            //заполнение игрового поля-шаблон игрового поля
            cout << "Теперь заполните игровое поле, выбрав необходимые координаты" << endl;
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
            while (count < Ship_Num) {
                Rasstanovka_kor(Battle_Pole_I);
                system("cls");
                cout << "Поле игрока" << endl;
                for (int i = 0; i < 11; i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                Pokaz_Ship(Battle_Pole_I);
                count++;
            }
            count = 0;
            //расстановка кораблей компьютером
            while (count < Ship_Num) {
                Rasstanovka_kor_Komp(Battle_Pole_Komp);
                count++;
            }
            //Pokaz_Ship(Battle_Pole_Komp); //показ поля компьютера (если необходимо, в идеале мы не видим корабли компьютера)
            count = 1;
            // процесс боя
            do {
                //ход игрока
                cout << "Счет " << Result_Hoda_I << "/" << Ship_Num << " (Игрок) - (Компьютер) " << Result_Hoda_K << "/" << Ship_Num << endl;
                cout << "Игрок наносит " << count << " удар" << endl;
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
                    // подсчет количества подбитых кораблей компьютера
                    Result(Battle_Pole_Komp);
                    Result_Hoda_I = Result(Battle_Pole_Komp);
                    if (Result_Hoda_I == Ship_Num) {
                        PobedaI = true;
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
                //ход компьютера
                do {
                    cout << "Счет " << Result_Hoda_I << "/" << Ship_Num << " (Игрок) - (Компьютер) " << Result_Hoda_K << "/" << Ship_Num << endl;
                    cout << "Компьютер наносит " << count << " удар" << endl;
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
                    // подсчет количества подбитых кораблей игрока
                    Result_Hoda_K = Result(Battle_Pole_I);
                    if (Result_Hoda_K == Ship_Num) {
                        PobedaKomp = true;
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
            } while (!PobedaI || !PobedaKomp);
            //результат игры
            if (PobedaI) {
                cout << "Выиграл Игрок! УРА!!!" << endl;
            }
            else if (PobedaKomp) {
                cout << "Выиграл Компьютер! УРА!!!" << endl;
            }
        }
        break;
        //игра со вторым игроком
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
                if (Ship_Num > 5)
                    cout << "Некорректное значение, повторите ввод" << endl;
            } while (Ship_Num > 5);
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
                    // подсчет количества подбитых кораблей компьютера
                    Result(Battle_Pole_I_2);
                    Result_Hoda_I = Result(Battle_Pole_I_2);
                    if (Result_Hoda_I == Ship_Num) {
                        Pobeda_I_1 = true;
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

                //ход второго игрока
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
                    // подсчет количества подбитых кораблей компьютера
                    Result(Battle_Pole_I_1);
                    Result_Hoda_I2 = Result(Battle_Pole_I_1);
                    if (Result_Hoda_I2 == Ship_Num) {
                        Pobeda_I_2 = true;
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
            } while (!Pobeda_I_1 || !Pobeda_I_2);
            //ПРИ ПОБЕДЕ НЕ ВЫХОДИМ ИЗ ЦИКЛА!!!

            //результат игры
            if (Pobeda_I_1) {
                cout << "Выиграл Игрок " << Igroki.Igrok_1 << endl;
            }
            else if (Pobeda_I_2) {
                cout << "Выиграл Игрок " << Igroki.Igrok_1 << endl;
            }
        }
        break;
        }
        cout << "Хотите повторить" << endl;
        cout << "       Y/N      " << endl;
        cin >> Povtor_igry;
        system("cls");
    } while (Povtor_igry == 'Y');
    system("pause");
}

// описание функций
int Zamena_B_na_Num(char Koord) {
    int y = 0;
    if (Koord == 'a') {
        y = 0;
    }
    else if (Koord == 'b') {
        y = 1;
    }
    else if (Koord == 'c') {
        y = 2;
    }
    else if (Koord == 'd') {
        y = 3;
    }
    else if (Koord == 'e') {
        y = 4;
    }
    else if (Koord == 'f') {
        y = 5;
    }
    else if (Koord == 'g') {
        y = 6;
    }
    else if (Koord == 'h') {
        y = 7;
    }
    else if (Koord == 'i') {
        y = 8;
    }
    else if (Koord == 'j') {
        y = 9;
    }
    return y;
}

void Rasstanovka_kor(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "Укажите первую координату (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату (строка) "; cin >> x;
        } while (x < 0 || x > 9);

    } while (arr[x][y] == 'K');
    arr[x][y] = 'K';
}

void Rasstanovka_kor_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            cout << "Укажите первую координату (столбец) "; cin >> St;
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату (строка) "; cin >> x;
        } while (x < 0 || x > 9);

    } while (arr[x][y] == 'H'); //корабль указывается в виде символа Н для различия от игрока №1
    arr[x][y] = 'H';
}

void Gor_Granica(char* arr, int size) {
    for (int i = 0; i < (SIZE + 1); i++) {  //верхняя граница координат
        cout << "|" << *(arr + i) << "|";
    }
}

void Pokaz_Ship(char arr[SIZE][SIZE]) {
    for (int x = 0; x < 10; x++) {
        cout << "|" << x << "|";
        for (int y = 0; y < 10; y++) {
            cout << "|" << arr[x][y] << "|";
        }
        cout << endl;
    }
}

void Rasstanovka_kor_Komp(char arr[SIZE][SIZE]) {
    int x, y;
    do {
        do {
            x = rand() % 5;
        } while (x < 0 || x > 9);
        do {
            y = rand() % 5;
        } while (y < 0 || y > 9);

    } while (arr[x][y] == 'K');
    arr[x][y] = 'K';
}

bool HodIgr(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "Укажите первую координату (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату (строка) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
        return true;   //для повторного удара в случае истины
    }
    else {
        arr[x][y] = '*';
        return false;
    }
}

bool HodIgr_1(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "Укажите первую координату (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату (строка) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'H') {
        arr[x][y] = 'O';
        return true;   //для повторного удара в случае истины
    }
    else {
        arr[x][y] = '*';
        return false;
    }
}

bool HodIgr_2(char arr[SIZE][SIZE]) {
    int x, y;
    char St;
    do {
        do {
            do {
                cout << "Укажите первую координату (столбец) "; cin >> St;
            } while (St != 'a' && St != 'b' && St != 'c' && St != 'd' && St != 'e' && St != 'f' && St != 'g' && St != 'h' && St != 'i' && St != 'j');
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату (строка) "; cin >> x;
        } while (x < 0 || x > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
        return true;   //для повторного удара в случае истины
    }
    else {
        arr[x][y] = '*';
        return false;
    }
}

void Pokaz_Udar(char arr1[SIZE][SIZE], char arr2[SIZE][SIZE]) {
    for (int x = 0; x < 10; x++) {
        cout << "|" << x << "|";
        for (int y = 0; y < 10; y++) {
            cout << "|" << arr2[x][y] << "|";
        }
        cout << "     ";
        cout << "|" << x << "|";
        for (int y = 0; y < 10; y++) {
            if (arr1[x][y] == 'O' || arr1[x][y] == '*') {
                cout << "|" << arr1[x][y] << "|";
            }
            else {
                cout << "| |";
            }
        }
        cout << endl;
    }
}

bool HodKomp(char arr[SIZE][SIZE])
{
    int x, y;
    do {
        do {
            x = rand() % 9;               //строка
        } while (x < 0 || x > 9);
        do {
            y = rand() % 9;              //столбец
        } while (y < 0 || y > 9);
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
        return true; //для повторного удара в случае истины
    }
    else {
        arr[x][y] = '*';
        return false;
    }
}

int Result(char arr[SIZE][SIZE]) {
    int count = 0;
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (arr[x][y] == 'O')
                count++;
        }
        cout << endl;
    }
    return count;
}

void Pokaz_Udar_2(char arr1[SIZE][SIZE], char arr2[SIZE][SIZE]) {
    for (int x = 0; x < 10; x++) {
        cout << "|" << x << "|";    //обозначение столбца координат по циклу
        for (int y = 0; y < 10; y++) {
            if (arr1[x][y] == 'O' || arr1[x][y] == '*') {
                cout << "|" << arr1[x][y] << "|";
            }
            else {
                cout << "| |";
            }
        }
        cout << "     ";
        cout << "|" << x << "|";//обозначение столбца координат по циклу
        for (int y = 0; y < 10; y++) {
            if (arr2[x][y] == 'O' || arr2[x][y] == '*') {
                cout << "|" << arr2[x][y] << "|";
            }
            else {
                cout << "| |";
            }
        }
        cout << endl;
    }
}