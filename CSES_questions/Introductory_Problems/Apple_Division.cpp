#define ll long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<ll> arr(n);
    ll sm = 0;
    for (auto &x : arr)
    {
        cin >> x;
        sm += x;
    }

    ll tot = LLONG_MAX;
    for (int i = 1; i < (1 << n); ++i)
    {
        ll x = 0, y = 0, cur = i, pos = 0;
        while (cur)
        {
            if (cur & 1)
                x += arr[pos];
            pos++;
            cur >>= 1;
        }
        y = sm - x;
        tot = min(tot, abs(y - x));
    }

    cout << tot << '\n';
}