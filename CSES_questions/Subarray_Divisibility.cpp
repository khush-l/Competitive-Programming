
#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long long> M(N);
	long long psums = 0;
	M[psums] = 1;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		psums += a;
		M[(psums % N + N) % N]++;
	}
	long long ans = 0;
	for (long long x : M) {
		ans += x * (x - 1) / 2;
	}
	cout << ans << endl;
}
