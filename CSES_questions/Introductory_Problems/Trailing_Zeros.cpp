#include <iostream>
#include <set>
#include <cmath>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;

    int tot = 0;
    for (int x = 5; x <= n; x *= 5)
        tot += (n / x);

    cout << tot << '\n';
}