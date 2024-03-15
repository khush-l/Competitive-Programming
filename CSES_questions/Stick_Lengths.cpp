
#include <bits/stdc++.h>
using namespace std;
# define ll long long

int main() {
	int N; cin >> N;
	vector <ll> sticks(N);
	for (int i=0;i<N;i++) {
		cin >> sticks[i];
	}
	sort(sticks.begin(), sticks.end());
	ll total = 0;
	ll mid = sticks[N/2];
	for (const ll &x : sticks) {
		total += abs(mid - x); 
	}
	cout << total;
}
