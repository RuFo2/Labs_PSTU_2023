#include <iostream>
#include"list.h"
#include"error.h"

int main()
{
    system("chcp 1251");
    int a = 0;
    while (true) {
        try
        {
            list<int> list1;
            list<int> list2;

            cout << endl;
            cout << "Введите количество элементов первого списка: ";
            cin >> list1;
            cout << "Введите количество элементов второго списка: ";
            cin >> list2;

            cout << endl;

            list<int> result = list1 + list2;
            cout << "Сумма списков: " << result << endl;

            cout << endl;

        }
        catch (IndexOutOfRangeError e) {
            e.PrintError();
            continue;
        }
        catch (NegativeIndexError e) {
            e.PrintError();
            continue;
        }
        catch (BasicError& err)
        {
            err.PrintError();
            char c;
            cout << "Хотите начать заново? (1/0): ";
            cin >> c;
            if (c == '0') break;
        }
    }
}

