
#include <bits/stdc++.h>
using namespace std;
# define ll long long

int main() {
	int N,X;
	cin >> N >> X;
	vector <int> g(N);
	vector <int> hg(N);
	for (int i = 0; i < N; ++i) cin >> g[i];
	sort(g.begin(), g.end());
	int i,total = 0;
	int j = N - 1;
	while (i < j) {
		if (g[i] + g[j] > X) {
			--j;
		} else {  
			++total; 
			hg[i] = hg[j] = true;
			++i;
			--j; 
		}
	}
	for (int i = 0; i < N; ++i) {
		total += hg[i] == false;
	}
	cout << total;
}
