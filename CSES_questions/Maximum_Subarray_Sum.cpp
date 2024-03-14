
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector <int> psum(N+1,0);
	int ma=INT_MIN;
	for (int i=0;i<N;i++) {
		psum[i+1]=psum[i];
		int val;
		cin >> val;
		psum[i+1]+=val;
		ma=max(ma,psum[i+1]);
	}
	cout << ma;
}