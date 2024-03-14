
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	int N, Q; cin >> N >> Q;
	vector<int> H(N+1,0), G(N+1,0), J(N+1,0);
	for (int i=0;i<N;i++) {
		int val;
		cin >> val;
		if (val==1){
			H[i]=1;
		}
		else if(val==2){
			G[i]=1;
		}
		else {
			J[i]=1;
		}
	}
	for (int i=1;i<N;i++){
		H[i]=H[i]+H[i-1];
		G[i]=G[i]+G[i-1];
		J[i]=J[i]+J[i-1];
	}
	for (int i=0;i<Q;i++){
		int a,b;
		cin >> a >> b;
		cout << (H[b-1]-H[a-2]) << " " << (G[b-1]-G[a-2]) << " " << (J[b-1]-J[a-2]) << "\n";
	}
}
