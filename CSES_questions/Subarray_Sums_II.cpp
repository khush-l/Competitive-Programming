#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	vector<int> vals(N);
	for (int i = 0; i < N; i++) { 
		cin >> vals[i]; 
		}
	long long sum = 0;
	long long ans = 0;
	map<long long, int> ind;
	ind[0] = 1;
	for (int x : vals) {
		sum += x;
		ans += ind[sum - X];
		ind[sum]++;
	}
	cout << ans << endl;
}
