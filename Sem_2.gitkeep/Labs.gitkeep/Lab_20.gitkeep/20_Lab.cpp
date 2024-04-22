#include <iostream>
#include <string>
using namespace std;

class Salary {
    string fullName;
    double salary;
    int bonus;
public:
    Salary() {
        fullName = "Buch Yan";
        salary = 20000;
        bonus = 15;
    };
    Salary(string str, double cash, int prize) {
        fullName = str;
        salary = cash;
        bonus = prize;
    };
    Salary(const Salary& tmp) {
        fullName = tmp.fullName;
        salary = tmp.salary;
        bonus = tmp.bonus;
    };

    void Show() {
        cout << fullName << ' ' << salary << ' ' << bonus << endl;
    }

    string getName() { return fullName; }
    double getSalary() { return salary; }
    int getBonus() { return bonus; }
    
    void setName(string str) { fullName = str; }
    void setSalary(double cash) { salary = cash; }
    void setBonus(int prize) { bonus = prize; }

    ~Salary(){}
};
int main()
{
    Salary salWithoutPar;
    Salary salWithPar("Buch", 5000, 9);
    Salary salPointer(salWithPar);
    salWithoutPar.Show();
    salWithPar.Show();
    salPointer.Show();
    salPointer.setBonus(24);
    cout << salWithoutPar.getName() << endl;
    return 0;
}
