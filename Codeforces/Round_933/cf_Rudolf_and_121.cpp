
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
      cin >> vals[i];
    }
    int answer = 1;
    for (int i = 0; i < n; i++) {
      if (i + 2 < n && vals[i] > 0) {
        vals[i + 2] -= vals[i];
        vals[i + 1] -= vals[i] * 2;
        vals[i] = 0;
      }
      answer &= vals[i] == 0;
    }
    cout << (answer ? "YES" : "NO") << '\n';
  }
  return 0;
}