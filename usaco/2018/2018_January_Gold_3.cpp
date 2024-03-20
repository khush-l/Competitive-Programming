#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);

    int length, colors, width; 
    cin >> length >> colors >> width;

    // Array to store dynamic programming values
    ll dp[length + 1]; 
    memset(dp, 0, sizeof(dp));

    ll total_ways = 1, current_ways = 0;
    for(int i = 1; i <= length; i++) {
        total_ways *= colors;
        total_ways %= MOD;
        current_ways += (colors - 1) * dp[i - 1];
        if(i == 1) 
            current_ways += colors;
        current_ways %= MOD;
        if(i >= width) {
            current_ways -= (colors - 1) * dp[i - width];
            if(i == width) 
                current_ways -= colors;
            current_ways = (current_ways + MOD) % MOD;
        }

        dp[i] += current_ways;
        dp[i] %= MOD;
    }

    cout << (total_ways - dp[length] + MOD) % MOD << '\n';
    
    return 0;
}
