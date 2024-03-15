
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector <pair<int,int>> movies(N);
	for (int i=0;i<N;i++) {
		cin >> movies[i].second >> movies [i].first;
	}
	sort(movies.begin(), movies.end());
	int total = 0;
	int val =0;
	for (int i =0;i<N;i++) {
		if (movies[i].second >= val) {
			total++;
			val = movies[i].first;
		}
	}
	cout << total;
}
