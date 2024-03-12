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
  vector<int> dp(S+1,1e9);
  dp[0] = 0;
  for (int i = 1; i <= S; i++) {
    for (int j = 0; j < N; j++) {
      if (i-vals[j] >= 0) {
	dp[i] = min(dp[i], dp[i-vals[j]]+1);
      }
    }
  }
  if (dp[S] == 1e9) {
    dp[S]=-1;
  }
  cout << dp[S] << endl;
}
