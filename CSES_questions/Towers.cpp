
#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main() {
	int N, K;
	cin >> N;
	multiset<int> vals;
	for (int i = 0; i < N; ++i) {
		cin >> K;
		auto it = vals.upper_bound(K);
		if (it == vals.end()) vals.insert(K);
		else {
			vals.erase(it);
			vals.insert(K);
		}
	}
	cout << vals.size();
}
