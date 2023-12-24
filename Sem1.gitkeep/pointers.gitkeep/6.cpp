#include <iostream>
#include <string>
int main(){
    setlocale(LC_ALL, "ru_RU");
    int countC = 0;
    int countV = 0;
    std::string st;
    std::cout << "Введите строку " << std::endl;
    std::cin >> st;
    const char* pt = st.c_str();
    for (int i = 0; i < st.length(); i++)
    {
        char tmp = *pt;
        std::cout << *pt << std::endl;
        if (tmp == L'a' || tmp == L'e' || tmp == L'y' || tmp == L'u' || tmp == L'i' || tmp == L'o')
        {
            countV++;
        }
        else { countC++; }
        pt++;
    }
    std::cout << "Кол-во гласных: " << countV << std::endl;
    std::cout << "Кол-во согласных: " << countC << std::endl;
    return 0;
}