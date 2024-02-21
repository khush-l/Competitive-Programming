// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main() {
	int N; cin >> N;
	vector<ll> base(N+1,0); 
    for (int i = 0; i < N; i++) {
        cin >> base[i];
    }
    ll max_sum = base[0];
    ll prefix_sum = base[0];

    for (int i = 1; i < N; i++) {
        prefix_sum = max(base[i], prefix_sum + base[i]);
        max_sum = max(max_sum, prefix_sum);
    }

    cout << max_sum << endl;

}
