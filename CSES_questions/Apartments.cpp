
#include <bits/stdc++.h>
using namespace std;
# define ll long long

int main() {
	int N,M,K; cin >> N >> M >> K;
	vector <ll> ppl(N);
	vector <ll> apa(M);
	for (int i = 0; i < N; ++i) cin >> ppl[i];
	for (int i = 0; i < M; ++i) cin >> apa[i];
	sort(ppl.begin(), ppl.end());
	sort(apa.begin(), apa.end());
	int total=0;
	int i = 0, j = 0;
	while (i < N && j < M) {
		if (abs(ppl[i] - apa[j]) <= K) {
			++i;
			++j;
			++total;
		} else {
			if (ppl[i] - apa[j] > K) {
				++j;
			}
			else {
				++i;
			}
		}
	}
	cout << total;
}
