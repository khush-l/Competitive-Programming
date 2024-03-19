#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> adjacency_list;

const int MAX_NODES = 1e5;
const int MOD = 1e9 + 7;
int dp[MAX_NODES][3];

vector<int> colors(MAX_NODES, -1);

void dfs(int node, int prev) {
    ll one_count = 1, two_count = 1, three_count = 1;
    for (auto adjacent : adjacency_list[node]) {
        if (adjacent != prev) {
            dfs(adjacent, node);
            one_count *= (dp[adjacent][1] + dp[adjacent][2]) % MOD;
            two_count *= (dp[adjacent][2] + dp[adjacent][0]) % MOD;
            three_count *= (dp[adjacent][0] + dp[adjacent][1]) % MOD;
            one_count %= MOD;
            two_count %= MOD;
            three_count %= MOD;
        }
    }
    
    dp[node][0] = one_count;
    dp[node][1] = two_count;
    dp[node][2] = three_count;

    // Update DP array based on the color restriction
    if (colors[node] >= 0) {
        int color = colors[node];
        dp[node][(color + 1) % 3] = 0;
        dp[node][(color + 2) % 3] = 0;
    }
}

int main() {
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

    int num_barns, num_painted;
    cin >> num_barns >> num_painted;

    adjacency_list.resize(num_barns);

    // Constructing the adjacency list
    for (int i = 0; i < num_barns - 1; ++i) {
        int barn1, barn2;
        cin >> barn1 >> barn2;
        barn1--; barn2--; // Convert to 0-based indexing
        adjacency_list[barn1].push_back(barn2);
        adjacency_list[barn2].push_back(barn1);
    }

    // Assigning colors to barns
    for (int i = 0; i < num_painted; ++i) {
        int barn, color;
        cin >> barn >> color;
        barn--; 
        colors[barn] = color - 1;
    }

    dfs(0, -1); // Start DFS from the root node

    cout << ((dp[0][0] + dp[0][1] + dp[0][2]) % MOD) << endl;

    return 0;
}
