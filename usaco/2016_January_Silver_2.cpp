
#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	int N; cin >> N;
	int ans = 0;
	vector<int> first(7, -1);
	first[0] = 0;
	int r = 0;
	for (int i = 1; i <= N; i++) {
		int val;
		cin >> val;
		r = (r + val) % 7;
		if (first[r] == -1) {
			first[r] = i;
		} else {
			ans = max(ans, i - first[r]);
		}
	}
	cout << ans << endl;
}
