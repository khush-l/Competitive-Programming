#define ll long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

ll pow10(int x)
{
    ll res = 1;
    for (int i = 0; i < x; i++)
        res *= 10;
    return res;
}

int solve(ll N)
{
    if (N < 9)
        return static_cast<int>(N) + 1;

    int len = 1;
    while (9 * pow10(len - 1) * len < N)
    {
        N -= 9 * pow10(len - 1) * len;
        len++;
    }

    string S = to_string(pow10(len - 1) + N / len);
    return static_cast<int>(S[N % len] - '0');
}

int main()
{
    int Q;
    ll K;
    cin >> Q;
    for (int q = 0; q < Q; q++)
    {
        cin >> K;
        cout << solve(K - 1) << '\n';
    }
}