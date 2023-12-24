#include <iostream>
#include <string>
using namespace std;
int main()
{
    int cntbig, cntsm, cntdiff, all;
    cntbig = cntsm = cntdiff = all = 0;
    string st;
    char big, sm;
    cin >> st >> big >> sm;
    const char* pt = st.c_str();
    for (int i = 1; i <= st.length(); i++)
    {
        if (*pt == big)
        {
            cntbig++;
        }
        else if (*pt == sm)
        {
            cntsm++;
        }
        else
        {
            cntdiff++;
        }
        pt++;
    }
    all = cntbig + cntsm + cntdiff;
    cout << "Countbig " << big << " =" << cntbig << endl;
    cout << "Countsm " << sm << " =" << cntsm << endl;
    cout << "Countdiff =" <<  cntdiff << endl;
    cout << "Countall =" << all << endl;
    return 0;
}