// морской бой-тестовый вариант в однопалубными кораблями
//Сделать разный размер поля на выбор игрока
// сделать повторный удар при попадании

#include <iostream>
#include <ctime>

using namespace std;

const int SIZE = 10;

//функция замены буквенного значения координаты столбца на цифру
int Zamena_B_na_Num(char Koord);
//функция расстановки кораблей игрока
void Rasstanovka_kor(char arr[SIZE][SIZE]);
//функция показа кораблей
void Pokaz_Ship(char arr[SIZE][SIZE]);
//функция расстановки кораблей компьютера
void Rasstanovka_kor_Komp(char arr[SIZE][SIZE]);
//функция хода игрока
void HodIgr(char arr[SIZE][SIZE]);
//функция отображения результатов хода (подбитые корабли и промахи игрока и компьютера)
void Pokaz_Udar_I(char arr1[SIZE][SIZE], char arr2[SIZE][SIZE]);
//функция отображения результатов хода (подбитые корабли и промахи компьютера)
void HodKomp(char arr[SIZE][SIZE]);
//функция определения попадания и назначения повторного удара
//bool Povtornyj_udar();
//функция подсчета количества подбитых кораблей
int Result(char arr[SIZE][SIZE]);


int main()
{
    setlocale(0, "ru");
    srand(time(0));
    const int SIZE = 10;
    char arr3[11] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' }; //массив для обозначения нумерации ячеек
    bool PobedaI = false, PobedaKomp = false;
    char Povtor_igry;
    int Tip_Igry;
    //процесс игры
    do {
        char Battle_Pole_I[SIZE][SIZE] = { {' ', ' ', ' '} };
        char Battle_Pole_I_2[SIZE][SIZE] = { {' ', ' ', ' '} };
        char Battle_Pole_Komp[SIZE][SIZE] = { {' ', ' ', ' '} };
        int Podbitye_Kor_I = 0; //количество подбитых кораблей на момент начала игры у игрока
        int Podbitye_Kor_Komp = 0; //количество подбитых кораблей на момент начала игры у игрока
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
            for (int i = 0; i < (SIZE + 1); i++) { //цикл для обозначения горизонтальной строки координат
                cout << "|" << arr3[i] << "|";
            }
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
            cout << "Теперь поле заполняет компьютер" << endl;
            while (count < Ship_Num) {
                Rasstanovka_kor_Komp(Battle_Pole_Komp);
                count++;
            }
            //Pokaz_Ship(Battle_Pole_Komp); //показ поля компьютера (если необходимо, в идеале мы не видим корабли компьютера)
            count = 1;
            // процесс боя
            do {
                //ход игрока
                cout << "Игрок наносит " << count << " удар" << endl;
                HodIgr(Battle_Pole_Komp);
                system("cls");
                cout << "           Поле игрока                         Компьютера" << endl;
                for (int i = 0; i < (SIZE + 1); i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << "     ";
                for (int i = 0; i < (SIZE + 1); i++) {
                    cout << "|" << arr3[i] << "|";
                }
                cout << endl;
                Pokaz_Udar_I(Battle_Pole_Komp, Battle_Pole_I);
                count++;
                // подсчет количества подбитых кораблей компьютера
                Result(Battle_Pole_Komp);
                int Result_Hoda = Result(Battle_Pole_Komp);
                if (Result_Hoda == Ship_Num) {
                    PobedaI = true;
                    break;
                }
                //ход компьютера
                cout << "Компьютер наносит " << count << " удар" << endl;
                cout << "Нажмите 0, что бы компьютер ударил" << endl;
                int Udar;
                do {
                    //  Povtor_Udara = false;
                    cin >> Udar;
                    if (Udar != 0)
                        cout << "Некорректное значение, попробуйте еще раз" << endl;
                    else
                        break;
                } while (Udar != 0);
                HodKomp(Battle_Pole_I);
                system("cls");
                cout << "           Поле игрока                         Компьютера" << endl;
                for (int i = 0; i < (SIZE + 1); i++) {
                    cout << "|" << arr3[i] << "|";            //цикл для обозначения горизонтальной строки координат
                }
                cout << "     ";
                for (int i = 0; i < (SIZE + 1); i++) {
                    cout << "|" << arr3[i] << "|";           //цикл для обозначения горизонтальной строки координат
                }
                cout << endl;
                Pokaz_Udar_I(Battle_Pole_Komp, Battle_Pole_I);
                count++;
                // подсчет количества подбитых кораблей игрока
                Result(Battle_Pole_I);
                if (Result_Hoda == Ship_Num) {
                    PobedaKomp = true;
                    break;
                }
            } while (!PobedaI || !PobedaKomp);
            //результат игры
            if (PobedaI) {
                cout << "Выиграл Игрок! УРА!!!" << endl;
            }
            else if (PobedaKomp) {
                cout << "Выиграл Компьютер! УРА!!!" << endl;
            }
            cout << "Хотите повторить" << endl;
            cout << "       Y/N      " << endl;
            cin >> Povtor_igry;
            system("cls");
            break;
            //игра со вторым игроком
        //case 2:
         //   break;
        }
    } while (Povtor_igry == 'Y');
    system("pause");
}
// описание функций
int Zamena_B_na_Num(char Koord) {
    int y;
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
            cout << "Укажите первую координату (столбец) "; cin >> St;
            y = Zamena_B_na_Num(St);
        } while (y < 0 || y > 9);
        do {
            cout << "Укажите вторую координату (строка) "; cin >> x;
            // x = a - 1;
        } while (x < 0 || x > 9);

    } while (arr[x][y] == 'K');
    arr[x][y] = 'K';
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

void HodIgr(char arr[SIZE][SIZE]) {
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
    } while (arr[x][y] == '*' || arr[x][y] == 'O');
    if (arr[x][y] == 'K') {
        arr[x][y] = 'O';
    }
    else {
        arr[x][y] = '*';
    }
}

void Pokaz_Udar_I(char arr1[SIZE][SIZE], char arr2[SIZE][SIZE]) {
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

void HodKomp(char arr[SIZE][SIZE])
{
    int x, y;
    char St;
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
    }
    else {
        arr[x][y] = '*';
    }
}

/*bool Povtornyj_udar() {
      int Povtor = false;
      if (Povtor_Udara = true) {
          Povtor = true;
      }
      else {
          Povtor = false;
      }
      return Povtor;
  }
  */

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