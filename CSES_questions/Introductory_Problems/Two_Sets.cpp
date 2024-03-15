#include <iostream>
#include <set>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;

    if ((n * (n + 1)) % 4 == 0)
    {
        cout << "YES\n";
        set<ll> a, b;
        for (int i = 1; i <= n; ++i)
            a.insert(i);
        ll tot = (n * (n + 1)) / 4;

        for (int i = n; i >= 1; --i)
        {
            if (i <= tot)
            {
                tot -= i;
                a.erase(i);
                b.insert(i);
            }
        }

        cout << a.size() << '\n';
        for (auto &x : a)
            cout << x << " ";
        cout << '\n';

        cout << b.size() << '\n';
        for (auto &x : b)
            cout << x << " ";
        cout << '\n';
    }
    else
        cout << "NO\n";
}






