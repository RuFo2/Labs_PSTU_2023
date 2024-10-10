#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <set>
#include <string>
#include <sstream>
#include <random>
#include <algorithm>
using namespace std;

void getSet(unordered_map<string, vector<int>>& sets) {
    string setName;
    vector<int> setOfNumbers;
    cout << "Введите название множества:" << endl;
    cin >> setName;
    if (!(sets.find(setName) == sets.end())) {
        cout << "Существует множество с таким именем." << endl;
        return;
    }

    int mode;
    cout << "Выберите способ:" << endl;
    cout << "1 - ручной ввод\n2 - случайный ввод\n3 - ввод по условию" << endl;
    cin >> mode;
    if (mode < 1 || mode > 3) {
        cout << "Выбран неверный способ" << endl;
        return;
    }

    int count;
    cout << "Сколько элементов будет содержаться в множестве?" << endl;
    cin >> count;
    if (count < 0 || count > 101) {
        cout << "Неверный размер множества." << endl;
        return;
    }

    if (mode == 1) {
        int value;
        for (int i = 0; i < count; i++) {
            cin >> value;
            int numberToFind = value;
            auto it = find(setOfNumbers.begin(), setOfNumbers.end(), numberToFind);
            if (value <= 50 && value >= -50 && it == setOfNumbers.end()) {
                setOfNumbers.push_back(value);
            }
            else if (it != setOfNumbers.end()) {
                cout << "Число уже содержится в множестве. Введите другое число" << endl;
                i--;
            }
            else {
                cout << "Значение выходит за пределы универсума. Введите другое число" << endl;
                i--;
            }
        }
    }
    else if (mode == 2) {           
        set<int> uniqueValues;
        int value;
        while (uniqueValues.size() < count) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dist(-50, 50);

            value = dist(gen);
            uniqueValues.insert(value);
        }
        copy(uniqueValues.begin(), uniqueValues.end(), back_inserter(setOfNumbers));

    }
    else if (mode == 3) {
        cout << "Выбор условий:" << endl;
        cout << "1 - Кратность числу y, начиная с х" << endl;
        cout << "2 - Заполнение положительными числами, начиная с х" << endl;
        cout << "3 - Заполнение отрицательными числами, начиная с х" << endl;
        cout << "4 - Заполнение в диапазоне" << endl;
        int conditionMode;
        cin >> conditionMode;
        if (conditionMode < 1 || conditionMode > 4) {
            cout << "Выбрано неверное условие" << endl;
            return;
        }
        else if (conditionMode == 1) {
            int x;
            cout << "Введите х" << endl;
            cin >> x;
            if (x > 50 || x < -50) {
                cout << "Неверный формат для x" << endl;
                return;
            }

            int y;
            cout << "Введите число для кратности у" << endl;
            cin >> y;

            int subCount = 0;
            int value = x;

            while (subCount < count) {
                if (value % y == 0) {
                    setOfNumbers.push_back(value);
                    subCount++;
                }
                if (++value == 51) {
                    cout << "Неверный размер множества" << endl;
                    return;
                }
            }
        }
        else if (conditionMode == 2) {
            int x;
            cout << "Введите х" << endl;
            cin >> x;
            if (x > 50 || x < 1) {
                cout << "Неверный формат для x" << endl;
                return;
            }
            int subCount = 0;
            int value = x;

            while (subCount < count) {
                setOfNumbers.push_back(value);
                subCount++;
                if (++value == 51) {
                    cout << "Неверный размер множества" << endl;
                    return;
                }
            }
        }
        else if (conditionMode == 3) {
            int x;
            cout << "Введите х" << endl;
            cin >> x;
            if (x > -1 || x < -50) {
                cout << "Неверный формат для x" << endl;
                return;
            }
            int subCount = 0;
            int value = x;

            while (subCount < count) {
                setOfNumbers.push_back(value);
                subCount++;
                if (++value == 0) {
                    cout << "Неверный размер множества" << endl;
                    return;
                }
            }
        }
        else if (conditionMode == 4) {
            int start, end;
            cout << "Начало и конец диапазона через пробел" << endl;
            cin >> start >> end;
            if (start >= end) {
                cout << "Начало диапазона больше конца" << endl;
                return;
            }
            else if (start < -50 || end > 50) {
                cout << "Неверный диапазон" << endl;
                return;
            }
            for (int i = start; i <= end; i++) {
                setOfNumbers.push_back(i);
            }
        }
    }
    sets[setName] = setOfNumbers;
}

vector<int> unionSet(vector<int> a, vector<int> b) {
    vector<int> unionResult = a;
    for (int i : b) {
        if (!(find(unionResult.begin(), unionResult.end(), i) != unionResult.end())) {
            unionResult.push_back(i);
        }
    }
    return unionResult;
}

vector<int> intersectionSet(vector<int> a, vector<int> b) {
    vector<int> intersectionResult;
    for (int i : a) {
        if (find(b.begin(), b.end(), i) != b.end()) {
            intersectionResult.push_back(i);
            b.erase(remove(b.begin(), b.end(), i), b.end());
        }
    }
    return intersectionResult;
}

vector<int> differenceSet(vector<int> a, vector<int> b) {
    vector<int> differenceResult = a;
    for (int i : b) {
        if (find(b.begin(), b.end(), i) != b.end()) {
            differenceResult.erase(remove(differenceResult.begin(), differenceResult.end(), i), differenceResult.end());
        }
    }
    return differenceResult;
}

vector<int> symmetricSet(vector<int> a, vector<int> b) {
    vector<int> symmetricResult = a;
    vector<int> tempB = b;
    for (int i : b) {
        if (find(symmetricResult.begin(), symmetricResult.end(), i) != symmetricResult.end()) {
            symmetricResult.erase(remove(symmetricResult.begin(), symmetricResult.end(), i), symmetricResult.end());
            tempB.erase(remove(tempB.begin(), tempB.end(), i), tempB.end());
        }
    }
    for (int i : tempB) {
        symmetricResult.push_back(i);
    }
    return symmetricResult;
}

vector<int> complimentSet(vector<int> a) {
    vector<int> complimentResult;
    for (int i = -50; i < 51; i++) {
        complimentResult.push_back(i);
    }
    for (int i : a) {
        if (find(complimentResult.begin(), complimentResult.end(), i) != complimentResult.end()) {
            complimentResult.erase(remove(complimentResult.begin(), complimentResult.end(), i), complimentResult.end());
        }
    }
    return complimentResult;
}

void operation(unordered_map<string, vector<int>>& sets) {
    vector<int> result;
    string setA, setB;
    
    cout << "Меню операций:" << endl;
    cout << "1 - Объединение" << endl;
    cout << "2 - Пересечение" << endl;
    cout << "3 - Разность" << endl;
    cout << "4 - Симметрическая разность" << endl;
    cout << "5 - Дополнение" << endl;
    int mode;
    cin >> mode;
    
    if (mode < 1 || mode > 5) {
        cout << "Неверный номер операции" << endl;
        return;
    }
    else if (mode == 5) {
        cout << "Введите множество для операции дополнения" << endl;
        cin >> setA;
        if (sets.find(setA) == sets.end()) {
            cout << "Неверное имя множества" << endl;
            return;
        }
    }
    else {
        cout << "Введите 2 множества для операции" << endl;
        cin >> setA >> setB;
        if ((sets.find(setA) == sets.end()) || (sets.find(setB) == sets.end())) {
            cout << "Неверное имя множества" << endl;
            return;
        }
    }

    if (mode == 1) {
        result = unionSet(sets[setA], sets[setB]);
    }
    else if (mode == 2) {
        result = intersectionSet(sets[setA], sets[setB]);
    }
    else if (mode == 3) {
        result = differenceSet(sets[setA], sets[setB]);
    }
    else if (mode == 4) {
        result = symmetricSet(sets[setA], sets[setB]);
    }
    else if (mode == 5) {
        result = complimentSet(sets[setA]);
    }

    string setName;
    cout << "Введите название созданного множества:" << endl;
    cin >> setName;
    if (!(sets.find(setName) == sets.end())) {
        cout << "Существует множество с таким именем." << endl;
        return;
    }
    sets[setName] = result;
}

void printSet(unordered_map<string, vector<int>> sets) {
    for (auto& pair : sets) {
        cout << pair.first << ": ";
        if (!pair.second.empty()) {
            for (int i = 0; i < pair.second.size(); i++) {
                cout << pair.second[i] << " ";
            }
        }
    cout << endl;
    }
}

vector<string> getOperations(string input) {
    vector<string> ops; 
    stack<int> check; 
    int exprNumber = 0; 
    int exprStart; 

    for (int i = 0; i < input.size(); i++) {
        char ch = input[i];

        if (ch == '(') {
            check.push(i);
        }
        else if (ch == ')') {
            exprStart = check.top();
            check.pop();
            string subExpr = input.substr(exprStart + 1, i - exprStart - 1); 
            ops.push_back(subExpr);

            input.replace(exprStart, i - exprStart + 1, to_string(exprNumber));
            exprNumber++;
            i = 0; 
        }
        else if (ch == '!' && !isdigit(input[i + 1]) && input[i + 1] != '(') {
            int setIndex;
            for (int j = i + 1; j < input.size(); j++) {
                if (input[j] == ' ' || input[j] == ')') {
                    setIndex = j;
                    break;
                }
            }

            string subExpr = input.substr(i, setIndex - i);

            string replacement = to_string(exprNumber++);
            input.replace(i, setIndex - i, replacement); 

            ops.push_back(subExpr);
            i = 0;
        }
        else if (ch == '!' && isdigit(input[i + 1])) {
            int setIndex;
            for (int j = i + 1; j < input.size(); j++) {
                if (input[j] == ' ' || input[j] == ')') {
                    setIndex = j;
                    break;
                }
            }

            string subExpr = input.substr(i, setIndex - i);
            ops.push_back(subExpr); 

            string replacement = to_string(exprNumber++);
            input.replace(i, setIndex - i, replacement);

            i = 0;
        }
    }
    ops.push_back(input);
    return ops;
}

bool isInteger(const string& str) {
    stringstream ss(str);
    int n;
    char c;
    return ss >> n && !(ss >> c);
}

void calc(unordered_map<string, vector<int>>& sets, vector<string> ops) {
    vector<vector<int>> results;
    for (int i = 0; i < ops.size(); i++) {
        string expr = ops[i];
        if (expr[0] != '!') {
            istringstream iss(expr);
            string set1, oper, set2;

            iss >> set1;
            iss >> oper;
            iss >> set2;

            if (!isInteger(set1) && !isInteger(set2)) {
                if ((sets.find(set1) == sets.end()) || (sets.find(set2) == sets.end())) {
                    cout << "Неверное имя множества" << endl;
                    return;
                }
                if (oper == "u") {
                    vector<int> exprRes = unionSet(sets[set1], sets[set2]);
                    results.insert(results.begin() + i, exprRes);
                }
                else if (oper == "i") {
                    vector<int> exprRes = intersectionSet(sets[set1], sets[set2]);
                    results.insert(results.begin() + i, exprRes);
                }
                else if (oper == "d") {
                    vector<int> exprRes = differenceSet(sets[set1], sets[set2]);
                    results.insert(results.begin() + i, exprRes);
                }
                else if (oper == "s") {
                    vector<int> exprRes = symmetricSet(sets[set1], sets[set2]);
                    results.insert(results.begin() + i, exprRes);
                }
                else {
                    cout << "Введено неверное действие" << endl;
                    return;
                }
            }

            else if (isInteger(set1) && !isInteger(set2)) {
                if ((sets.find(set2) == sets.end())) {
                    cout << "Неверное имя множества" << endl;
                    return;
                }
                if (oper == "u") {
                    vector<int> exprRes = unionSet(results[stoi(set1)], sets[set2]);
                    results.insert(results.begin() + i, exprRes);
                }
                else if (oper == "i") {
                    vector<int> exprRes = intersectionSet(results[stoi(set1)], sets[set2]);
                    results.insert(results.begin() + i, exprRes);
                }
                else if (oper == "d") {
                    vector<int> exprRes = differenceSet(results[stoi(set1)], sets[set2]);
                    results.insert(results.begin() + i, exprRes);
                }
                else if (oper == "s") {
                    vector<int> exprRes = symmetricSet(results[stoi(set1)], sets[set2]);
                    results.insert(results.begin() + i, exprRes);
                }
                else {
                    cout << "Введено неверное действие" << endl;
                    return;
                }
            }

            else if (!isInteger(set1) && isInteger(set2)) {
                if ((sets.find(set1) == sets.end())) {
                    cout << "Неверное имя множества" << endl;
                    return;
                }
                if (oper == "u") {
                    vector<int> exprRes = unionSet(sets[set1], results[stoi(set2)]);
                    results.insert(results.begin() + i, exprRes);
                }
                else if (oper == "i") {
                    vector<int> exprRes = intersectionSet(sets[set1], results[stoi(set2)]);
                    results.insert(results.begin() + i, exprRes);
                }
                else if (oper == "d") {
                    vector<int> exprRes = differenceSet(sets[set1], results[stoi(set2)]);
                    results.insert(results.begin() + i, exprRes);
                }
                else if (oper == "s") {
                    vector<int> exprRes = symmetricSet(sets[set1], results[stoi(set2)]);
                    results.insert(results.begin() + i, exprRes);
                }
                else {
                    cout << "Введено неверное действие" << endl;
                    return;
                }
            }

            else if (isInteger(set1) && isInteger(set2)) {
                if (oper == "u") {
                    vector<int> exprRes = unionSet(results[stoi(set1)], results[stoi(set2)]);
                    results.insert(results.begin() + i, exprRes);
                }
                else if (oper == "i") {
                    vector<int> exprRes = intersectionSet(results[stoi(set1)], results[stoi(set2)]);
                    results.insert(results.begin() + i, exprRes);
                }
                else if (oper == "d") {
                    vector<int> exprRes = differenceSet(results[stoi(set1)], results[stoi(set2)]);
                    results.insert(results.begin() + i, exprRes);
                }
                else if (oper == "s") {
                    vector<int> exprRes = symmetricSet(results[stoi(set1)], results[stoi(set2)]);
                    results.insert(results.begin() + i, exprRes);
                }
                else {
                    cout << "Введено неверное действие" << endl;
                    return;
                }
            }
        }

        else if (expr[0] == '!') {
            expr.erase(0, 1);
            if (isInteger(expr)) {
                vector<int> exprRes = complimentSet(results[stoi(expr)]);
                results.insert(results.begin() + i, exprRes);
            }
            else {
                vector<int> exprRes = complimentSet(sets[expr]);
                results.insert(results.begin() + i, exprRes);
            }
        }
    }

    string setName;
    cout << "Введите название множества:" << endl;
    cin >> setName;
    if (!(sets.find(setName) == sets.end())) {
        cout << "Существует множество с таким именем." << endl;
        return;
    }
    else {
        sets[setName] = results.back();
    }
}

void formula(unordered_map<string, vector<int>>& sets) {
    string expression;
    cout << "Введите выражение:" << endl;
    cout << "u - объединение" << endl;
    cout << "i - пересечение" << endl;
    cout << "d - разность" << endl;
    cout << "s - симметрическая разность" << endl;
    cout << "! - дополнение" << endl;
    cout << "Действия разделяются скобками, между выражением и действием ставится пробел (кроме дополнения)" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, expression);

    vector<string> ops = getOperations(expression);
   
    calc(sets, ops);
}

void handleOption(int option, unordered_map<string, vector<int>>& sets) {
    if (option == 1) {
        getSet(sets);
    }
    else if (option == 2) {
        operation(sets);
    }
    else if (option == 3) {
        formula(sets);
    }
    else if (option == 4) {
        printSet(sets);
    }
    else if (option == 0) {
        cout << "Выход" << endl;
    }
    else {
        cout << "Неверный формат ввода" << endl;
    }
}

int main() {
  setlocale(LC_ALL, "Russian");
  unordered_map<string, vector<int>> sets;
  int choice;
  do {
    cout << "Меню:" << endl;
    cout << "1 - Добавление множества" << endl;
    cout << "2 - Операции между множествами" << endl;
    cout << "3 - Вычисление по формуле" << endl;
    cout << "4 - Вывод множеств" << endl;
    cout << "0 - Выход" << endl;
    cin >> choice;
    handleOption(choice,sets);
  } while (choice != 0);
}
