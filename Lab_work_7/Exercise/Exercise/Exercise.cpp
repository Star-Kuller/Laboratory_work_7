#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void N_1();
void N_2();
void N_3();
void N_4();
void N_5();

template <typename T>
void pushBack(T*& arr, int& size, T newValue) { // увеличивает размер динамического массива на 1 ячейку и вносит в него новые данные, инкрементирует size
    T* newArr = new T[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = newValue;
    size++;
    delete[] arr;

    arr = newArr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int selected;
    while (true) { //селектор заданий
        cout << "\033[2J\033[1;1H"; //очищение экрана
        cout << ">--------------------[Главное меню]--------------------<\n";
        cout << "0 - Завершить работу\n1,2,3,4,5 - доступные задания\n";
        cout << "--------------------------------------------------------\n";
        cout << "Выберите задание или 0: "; cin >> selected;
        switch (selected)
        {
        case 0:
            return 0;
            break;
        case 1:
            N_1();
            break;
        case 2:
            N_2();
            break;
        case 3:
            N_3();
            break;
        case 4:
            N_4();
            break;
        case 5:
            N_5();
            break;
        default:
            break;
        }
    }
    return 0;
}


void addarrays(float* arr0, float* arr1, float* arr2) {
    for (int i = 0; i < 5; i++)
    {
        *(arr2 + i) = *(arr0 + i) + *(arr1 + i);
    }
}

void N_1()
{
	cout << "\033[2J\033[1;1H"; //очищение экрана
    cout << ">----------------[Начало выполнения N_1]----------------<\n";
    float arr0[5] = {1.267f, 235.46f, 3526.436f, 3254.245f, 426.64f};
    float arr1[5] = { 35.23f, 10.368f, 12.04f, 66.006f, 1.0f };
    float arr2[5];
    addarrays(arr0, arr1, arr2);
    cout << "\nПервый массив:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << *(arr0 + i) << "\n";
    }
    cout << "\nВторой массив:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << *(arr1 + i) << "\n";
    }
    cout << "\nТретий массив(Результат):\n";
    for (int i = 0; i < 5; i++)
    {
        cout << *(arr2 + i) << "\n";
    }
    cout << "\n>----------------[Конец выполнения N_1]----------------<\n";
    system("pause");
}

int compstr(const char* s1, const char* s2)
{
    int n = 0;
    while (*(s1 + n) != '\0' || *(s2 + n) != '\0')
    {
        if (*(s1 + n) > *(s2 + n))
            return 1;
        if (*(s1 + n) < *(s2 + n))
            return -1;
        n++;
    }
    return 0;
}

void N_2()
{
    cout << "\033[2J\033[1;1H"; //очищение экрана
    cout << ">----------------[Начало выполнения N_2]----------------<\n";
    string s1, s2;
    cout << "Введите первую строку: \n";
    cin.ignore();
    getline(cin, s1);
    cout << "Введите вторую строку: \n";
    getline(cin, s2);
    cout << "\nРезультат: ";
    char* sc1 = new char[s1.length() + 1];
    s1.copy(sc1, s1.length());
    *(sc1+s1.length()) = '\0';
    char* sc2 = new char[s2.length() + 1];
    s2.copy(sc2, s2.length());
    *(sc2+s2.length()) = '\0';
    cout << compstr(sc1, sc2);
    cout << "\n>----------------[Конец выполнения N_2]----------------<\n";
    delete[] sc1;
    delete[] sc2;
    system("pause");
}

void N_3()
{
    cout << "\033[2J\033[1;1H"; //очищение экрана
    cout << ">----------------[Начало выполнения N_3]----------------<\n";
    int* arrРointer[10];
    int a0[10], a1[10], a2[10], a3[10], a4[10], a5[10], a6[10], a7[10], a8[10], a9[10];
    arrРointer[0] = a0;
    arrРointer[1] = a1;
    arrРointer[2] = a2;
    arrРointer[3] = a3;
    arrРointer[4] = a4;
    arrРointer[5] = a5;
    arrРointer[6] = a6;
    arrРointer[7] = a7;
    arrРointer[8] = a8;
    arrРointer[9] = a9;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arrРointer[i][j] = (i+1) * (j+1);
        }
    }
    cout << "Массив указателей на массивы содержит массивы с элементами: \n";
    for (int i = 0; i < 10; i++)
    {
        printf("Массив %d cодержит: ", i);
        for (int j = 0; j < 10; j++)
        {
            printf("%4d | ", arrРointer[i][j]);
        }
        cout << "\n";
    }
    cout << "\n>----------------[Конец выполнения N_3]----------------<\n";
    system("pause");
}

void N_4()
{
    cout << "\033[2J\033[1;1H"; //очищение экрана
    cout << ">----------------[Начало выполнения N_4]----------------<\n";
    int sizeArrs = 0,
        sizeArrPointers = 0;
    cout << "Введите размер массива указателей: ";
    cin >> sizeArrPointers;
    cout << "Введите размер массивов: ";
    cin >> sizeArrs;
    cout << "--------------------------------------------------------\n";
    int** arrРointer = new int*[sizeArrPointers];
    for (int i = 0; i < sizeArrPointers; i++)
    {
        arrРointer[i] = new int[sizeArrs];
    }
    for (int i = 0; i < sizeArrPointers; i++)
    {
        for (int j = 0; j < sizeArrs; j++)
        {
            arrРointer[i][j] = (i + 1) * (j + 1);
        }
    }
    cout << "Массив указателей на массивы содержит массивы с элементами: \n";
    for (int i = 0; i < sizeArrPointers; i++)
    {
        printf("Массив %3d cодержит: ", i);
        for (int j = 0; j < sizeArrs; j++)
        {
            printf("%4d | ", arrРointer[i][j]);
        }
        cout << "\n";
    }
    cout << "\n>----------------[Конец выполнения N_4]----------------<\n";
    system("pause");
}

void N_5()
{
    cout << "\033[2J\033[1;1H"; //очищение экрана
    cout << ">----------------[Начало выполнения N_5]----------------<\n";
    struct person
    {
        char* name;
        int salary;
    };
    int size = 5;
    string nameInput;
    cout << "Введите количество сотрудников: ";
    cin >> size;
    person* persArr = new person[size];
    for (int i = 0; i < size; i++)
    {
        cout << "\nВведите имя " << i+1 << "-го сторудника: ";
        cin >> nameInput;
        (persArr + i)->name = new char[nameInput.length()];
        char* temp = new char[nameInput.length() + 1];
        nameInput.copy(temp, nameInput.length());
        *(temp + nameInput.length()) = '\0';
        (persArr + i)->name = temp;
        cout << "Введите зарплату " << i+1 << "-го сторудника: ";
        cin >> (persArr + i)->salary;
    }
    cout << "--------------------------------------------------------";
    for (int i = 0; i < size; i++)
    {
        cout << "\n\nИмя " << i+1 << "-го сторудника: ";
        cout << (persArr + i)->name;
        cout << "\nЗарплата " << i+1 << "-го сторудника: ";
        cout << (persArr + i)->salary;
    }
    cout << "\n\n>----------------[Конец выполнения N_5]----------------<\n";
    system("pause");
}