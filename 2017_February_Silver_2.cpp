
#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	int N, K, B;
	cin >> N >> K >> B;
	int sigs[N+1]={0};
	int presum[N+1]={0};
	for (int i = 0; i < B; i++) {
		int val;
		cin >> val;
		sigs[val]++;
	}
	for (int i = 0; i < N; i++) { 
		presum[i + 1] = sigs[i + 1] + presum[i]; 
		}

	int ma = INT_MAX;
	for (int i = 0; i <= N - K; i++) {
		ma = min(ma, presum[i + K] - presum[i]);
	}
	cout << ma << '\n';
}
