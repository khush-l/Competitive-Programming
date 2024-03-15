
#include <bits/stdc++.h>
using namespace std;
# define ll long long


int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> t(N);
    for (int i = 0; i < N; i++){
		cin >> t[i].first >> t[i].second;
	}
    sort(t.begin(), t.end());
    ll time = 0;
    ll ans = 0;
    for (auto i: t){
        time += i.first;
        ans += i.second - time;
    }
    cout << ans;
}
