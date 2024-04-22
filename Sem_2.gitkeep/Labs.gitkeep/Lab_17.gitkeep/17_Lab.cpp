#include "boyerSearch.h"
#include "knuthSearch.h"


int main() {
    setlocale(LC_ALL, "RU");
    cout << "Выберите способ сортировки:\n"
        << "1 - boyerSearch\n"
        << "2 - knuthSearch\n";
    int number;
    cin >> number;
    switch (number) {
    case 1: {
        boyerSearch("vzglyanivokrugoglyanisnazadduhi", "oglyanis");
        break;
    }
    case 2: {
        knuthSearch("vzglyanivokrugognyanisnazadduhi", "vokrug");
        break;
    }
    default: {
        cout << "1 or 2" << endl;
        break;
    }
    }
    return 0;
}