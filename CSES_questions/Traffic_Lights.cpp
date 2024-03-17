#include <iostream>
#include <set>
#define ll long long


using namespace std;

int main()
{
    ll x;
    int n;
    cin >> x >> n;

    set<pair<ll, ll>> a, b;
    a.insert({x, x});
    b.insert({x, x});

    while (n--)
    {
        ll val;
        cin >> val;

        auto it = a.lower_bound({val, 0});
        auto cur = *it;

        a.erase(it);
        a.insert({val, cur.second - (cur.first - val)});
        a.insert({cur.first, cur.first - val});

        b.erase({cur.second, cur.first});
        b.insert({cur.second - (cur.first - val), val});
        b.insert({cur.first - val, cur.first});

        cout << b.rbegin()->first << ' ';
    }

    cout << '\n';
}
