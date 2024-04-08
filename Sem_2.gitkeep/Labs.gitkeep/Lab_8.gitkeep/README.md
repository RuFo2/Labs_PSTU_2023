# Лабораторная работа №8
>[!NOTE]
>Тема : "Блоковый ввод-вывод"
>Цель : Работа с двоичными файлами, организация вводавывода структурированной информации и ее хранение навнешних носителях.
# Вариант № 21
Сформировать двоичный файл из элементов, заданной в варианте структуры, распечатать его содержимое, выполнить
удаление и добавление элементов в соответствии со своим вариантом, используя для поиска удаляемых или добавляемых
элементов функцию. Формирование, печать, добавление и удаление элементов оформить в виде функций. Предусмотреть
сообщения об ошибках при открытии файла и выполнении операций ввода/вывода.
Структура "Автомобиль":
- марка;
- серийный номер;
- регистрационный номер;
- год выпуска.
Удалить 3 элемента из начала файла, добавить элемент
поле элемента с указанным регистрационным номером.
# Блок-схема
-
# Код программы
```cpp
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>

using namespace std;

struct Car
{
    string brand;
    string serialNumb;
    string regNumb;
    string releaseYear;
};

string randStr() {
    string str;
    static const char absd[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < rand() % 8 + 3; i++) {
        str += absd[rand() % 26];
    }
    return str;
}

string randNum(int len) {
    string numPh = "7";
    for (int i = 0; i < len; i++) numPh += rand() % 10 + 0x30;
    return numPh;
}

void setStruct(Car arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i].brand = randStr();
        arr[i].serialNumb = randNum(6);
        arr[i].regNumb = randNum(6);
        arr[i].releaseYear = randNum(4);
    }
}

void showArr(Car arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i].brand << ' '
            << arr[i].serialNumb << ' '
            << arr[i].regNumb << ' '
            << arr[i].releaseYear << endl;
    }
}

int main()
{
    srand(time(0));
    int count = 5;
    Car arr[count];
    Car outArr[count];
    setStruct(arr, 5);
    FILE* fp;
    fp = fopen("t.txt", "wb");
    if (fp == NULL) { fputs("fopen error", fp); fclose(fp); }

    for (int j = 0; j < count; j++)
    {
        fwrite(&arr[j], sizeof(Car), 1, fp);
    }
    fclose(fp);

    FILE* pFile;

    pFile = fopen("t.txt", "rb");

    int i = 0;
    while (!feof(pFile) && i <= count)
    {
        fread(&outArr[i], sizeof(Car), 1, pFile);
        i++;
    }
    fclose(pFile);

    showArr(outArr, 5);
    cout << endl;
    for (int j = 0, sizeS = count; j < 3; j++, sizeS--) {
        for (int k = 0; k < sizeS - 1; k++) {
            outArr[k] = outArr[k + 1];
        }
    }
    count -= 3;
    showArr(outArr, count);
    cout << endl;

    string str;
    cin >> str;

    for (int i = 0; i < count; i++)
    {
        if (outArr[i].regNumb == str)
        {
            outArr[i].brand = randStr();
            outArr[i].serialNumb = randNum(6);
            outArr[i].regNumb = randNum(6);
            outArr[i].releaseYear = randNum(4);
        }
    }

    showArr(outArr, count);
    cout << endl;

    fp = fopen("t.txt", "wb");
    if (fp == NULL) { fputs("fopen error", fp); fclose(fp); }

    for (int j = 0; j < count - 3; j++)
    {
        fwrite(&outArr[j], sizeof(Car), 1, fp);
    }
    fclose(fp);


    return 0;
}
```
