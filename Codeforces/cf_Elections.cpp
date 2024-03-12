#include <bits/stdc++.h>
using namespace std;
//# define int long long

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int a,b,c;
		cin >>a >>b >> c;
		cout << max(0,max(b,c)+1-a)<< " "<<max(0,max(a,c)+1-b)<< " "<<max(0,max(a,b)+1-c)<< "\n";
	}
}
