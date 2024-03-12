#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;
int main() {
  int N;
  cin >> N;
  vector<int> dp(N+1,0);
  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 6; j++) {
	  if(i-j >=0){ 
      dp[i] += dp[i-j];
	  dp[i] %= MOD;
	  }
    }
  }
  cout << dp[N] << endl;
}
