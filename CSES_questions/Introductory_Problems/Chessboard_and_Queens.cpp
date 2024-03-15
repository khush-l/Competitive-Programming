#define ll long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<vector<bool>> board(8, vector<bool>(8));

int solve(int j = 0, int x = 0, int d1 = 0, int d2 = 0)
{
    if (j == 8)
        return 1;

    int tot = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (board[i][j] && !(x & (1 << i)) && !(d1 & (1 << (i + j))) && !(d2 & (1 << (i - j + 8))))
            tot += solve(j + 1, (x | (1 << i)), (d1 | (1 << (i + j))), (d2 | (1 << (i - j + 8))));
    }
    return tot;
}

int main()
{
    for (int i = 0; i < 8; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 8; ++j)
            board[i][j] = (str[j] != '*');
    }
    cout << solve() << '\n';
}