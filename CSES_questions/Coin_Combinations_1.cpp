#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;
int main() {
  int N, S;
  cin >> N >> S;
  vector<int> vals(N,0);
  for (int i=0;i<N;i++) {
    cin >> vals[i];
  }
  vector<int> dp(S+1,0);
  dp[0] = 1;
  for (int i = 1; i <= S; i++) {
    for (int j = 0; j < N; j++) {
      if (i-vals[j] >= 0) {
	(dp[i] += dp[i-vals[j]]) %= MOD;
      }
    }
  }
  cout << dp[S] << endl;
}
