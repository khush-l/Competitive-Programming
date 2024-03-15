#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    string str;
    cin >> str;

    vector<int> cnt(26, 0);
    for (auto &x : str)
        cnt[x - 'A']++;

    bool allow = (str.size() % 2 == 1);
    string side, m = "";
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] == 0)
            continue;
        if (cnt[i] & 1)
        {
            if (allow)
            {
                allow = false;
                m = string(cnt[i], ('A' + i));
            }
            else
            {
                cout << "NO SOLUTION\n";
                return 0;
            }
        }
        else
            side += string(cnt[i] / 2, ('A' + i));
    }

    string otherSide = side;
    reverse(otherSide.begin(), otherSide.end());

    cout << (side + m + otherSide) << '\n';
}