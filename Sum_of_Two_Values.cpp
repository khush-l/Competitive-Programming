#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
    int n;
    ll x;
    cin >> n >> x;

    vector<pair<int, int>> vals(n);
    for (int i = 0; i < n; ++i)
    {
        ll a;
        cin >> a;
        vals[i] = {a, i};
    }
    sort(vals.begin(), vals.end());
    int j=n-1;
    for (int i = 0; i < j;)
    {
        if (vals[i].first + vals[j].first == x)
        {
            cout << vals[i].second + 1 << " " << vals[j].second + 1;
            return 0;
        }
        if (vals[i].first + vals[j].first < x)
            i++;
        else
            j--;
    }

    cout << "IMPOSSIBLE";
}
