#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int check(string st) {
    const char* pt = st.c_str();
    int cons = 0;
    for (int i = 0; i < st.length(); i++)
    {
        char tmp = *pt;
        if (tmp > 65 && tmp < 123 && tmp != 69 && tmp != 73 && tmp != 79 && tmp != 85 && tmp != 89 && tmp != 97 && tmp != 101 && tmp != 105 && tmp != 111 && tmp != 117 && tmp != 121)
            cons++;
        pt++;
    }
    return cons;
}

int main() {
    ifstream F1("F1.txt");
    ofstream F2("F3.txt");
    string str, last;
    string word;
    getline(F1, str);
    int i = 0;
    while (str[i] != ' ')
    {
        word += str[i];
        i++;
    }
    F2 << str << endl;
    int j = 0;
    i = 0;
    while (getline(F1, str))
    {
        while (i < str.size() && j != word.size())
        {
            if (str[i] == word[j])
            {
                i++;
                j++;

            }
            else
            {
                while (str[i] != ' ' && i < str.size())
                    i++;
                i++;
                j = 0;
            }
        }
        if (j == word.size())
        {
            F2 << str << endl;
            last = str;
        }
        j = 0;
        i = 0;

    }
    cout << check(last) << endl;
    F1.close();
    F2.close();

    return 0;
}
