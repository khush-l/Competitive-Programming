#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll y, x;
        cin >> y >> x;

        ll m = max(x, y);
        ll tot = (m - 1) * (m - 1);

        if (m & 1)
            tot += (x + (m - y));
        else
            tot += (y + (m - x));

        cout << tot << '\n';
    }
}






