#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        ll temp = (i - 1) * (i + 4);
        ll tot = temp * (i * i - 3 * i + 4) / 2;
        cout << tot << '\n';
    }
}






