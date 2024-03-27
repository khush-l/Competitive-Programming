#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    int numCows, maxWeight, leftLimit = 0, rightLimit = 1e6, result = 0;
    cin >> numCows >> maxWeight;

    vector<int> weight(numCows + 1), talent(numCows + 1);
    for(int i = 1; i <= numCows; i++) 
        cin >> weight[i] >> talent[i];

    // Binary search to find the optimal talent per weight
    while(leftLimit <= rightLimit) {
        int mid = (leftLimit + rightLimit) / 2;

        // Dynamic programming array to store the maximum total talent achieved for each weight
        vector<vector<ll>> dp(numCows + 1, vector<ll>(maxWeight + 1, -1e18));
        dp[0][0] = 0;

        for(int i = 0; i < numCows; i++) {
            for(int j = 0; j <= maxWeight; j++) {
                // Not taking the current cow
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                // Taking the current cow if the weight limit allows
                dp[i + 1][min(maxWeight, j + weight[i + 1])] = max(dp[i + 1][min(maxWeight, j + weight[i + 1])],
                    dp[i][j] + 1000ll * talent[i + 1] - 1ll * mid * weight[i + 1]);
            }
        }

        // Check if it's possible to achieve a non-negative total talent with the given mid value
        if(dp[numCows][maxWeight] >= 0) 
            result = mid, leftLimit = mid + 1;
        else 
            rightLimit = mid - 1;
    }

    cout << result << '\n';
}
