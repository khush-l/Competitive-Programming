#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int num_cows;
    cin >> num_cows;
    vector<int> cow_weights(num_cows);
    for(int i = 0; i < num_cows; i++){
        cin >> cow_weights[i];
    }
    sort(cow_weights.begin(), cow_weights.end(), greater<int>());
    int line_count = 0;
    for(int i = 0; i < num_cows; i++){
        // A cow with weight greater than or equal to its position in line
        if (cow_weights[i] >= i) {
            line_count++;
        }
    }
    cout << line_count;
}
