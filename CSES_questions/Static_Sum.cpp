// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

int main() {
	int N, Q; cin >> N >> Q;
	ll base[N], psum[N+1];
    for (int i = 0; i < N; i++) {
        cin >> base[i];
        psum[i+1]=psum[i]+base[i];
    }

    while (Q--) {
        int val1, val2;
        cin >> val1 >> val2;
        cout << psum[val2] - psum[val1] << endl;
    }
}
