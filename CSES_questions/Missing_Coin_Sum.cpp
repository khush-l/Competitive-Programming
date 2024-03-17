#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;


int main()
{
    int n;
    cin >> n;
    int vals[n];
    ll tot = 0;

    for (int i = 0; i < n; i++)
        cin >> vals[i];
    
    sort(vals, vals+n);

    tot = 1;
    for (int i = 0; i < n && vals[i] <= tot; i++)
        tot += vals[i];

    cout << tot << '\n';
}
