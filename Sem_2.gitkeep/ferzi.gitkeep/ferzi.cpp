#include <iostream>
using namespace std;
int board[8][8];
const int queen = -1;
void resetboard();
void showboard();
bool checkQ(int i);
void delQ(int i, int j);
void setQ(int i, int j);

void resetboard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }
}
void showboard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == queen) { cout << "[Q] "; }
            else { cout << "[ ] "; }
        }
        cout << endl;
    }
}
void setQ(int i, int j)
{
    int d;
    for (int x = 0; x < 8; ++x)
    {
        board[x][j]++;
        board[i][x]++;
        d = j - i + x;
        if (d >= 0 && d < 8) { board[x][d]++; }
        d = j + i - x;
        if (d >= 0 && d < 8) { board[x][d]++; }
    }
    board[i][j] = queen;
}
void delQ(int i, int j)
{
    int d;
    for (int x = 0; x < 8; ++x)
    {
        board[x][j]--;
        board[i][x]--;
        d = j - i + x;
        if (d >= 0 && d < 8) { board[x][d]--; }
        d = j + i - x;
        if (d >= 0 && d < 8) { board[x][d]--; }
    }
    board[i][j] = 0;
}
bool checkQ(int i)
{
    bool result = false;
    for (int j = 0; j < 8; ++j)
    {
        if (board[i][j] == 0)
        {
            setQ(i, j);
            if (i == 7) {
                result = true;
            }
            else if (!(result = checkQ(i + 1)))
            {
                delQ(i, j);
            }

        }
        if (result) { break; }
    }
    return result;
}
int main()
{
    resetboard();
    checkQ(0);
    showboard();
    return 0;
}
