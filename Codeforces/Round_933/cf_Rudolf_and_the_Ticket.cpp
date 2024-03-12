
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> left_pocket(n), right_pocket(m);
        
        for (int i = 0; i < n; ++i) {
            cin >> left_pocket[i];
        }
        
        for (int i = 0; i < m; ++i) {
            cin >> right_pocket[i];
        }

        sort(right_pocket.begin(), right_pocket.end());

        int count = 0;
        for (int i = 0; i < n; ++i) {
            int max_value = k - left_pocket[i];
            count += upper_bound(right_pocket.begin(), right_pocket.end(), max_value) - right_pocket.begin();
        }
        
        cout << count << "\n";
    }
    return 0;
}
