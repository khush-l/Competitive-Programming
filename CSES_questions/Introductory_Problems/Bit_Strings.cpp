#include <iostream>
#include <set>
#include <cmath>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

ll fastpow2(int x) {
    ll res = 1;
    ll a = 2;
    while (x > 0) {
        if (x & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        x >>= 1;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    cout << fastpow2(N) << endl;
    return 0;
}