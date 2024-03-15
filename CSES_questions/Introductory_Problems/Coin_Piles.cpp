#include <iostream>
#include <set>
#include <cmath>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        if ((2 * a - b) % 3 == 0 && (2 * b - a) % 3 == 0)
        {
            ll x = (2 * a - b) / 3, y = (2 * b - a) / 3;
            if (x >= 0 && y >= 0 && x <= min(a, b) && y <= min(a, b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }
}