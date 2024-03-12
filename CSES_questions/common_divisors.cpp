
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	int maxv=0;
	int nums[N];
	for (int i=0;i<N;i++){
		int val;
		cin >> val;
		nums[i]=val;

	}
	for (int i=0;i<N-1;i++){
		for (int j=i+1;j<N;j++) {
		int count = gcd(nums[i],nums[j]);
		maxv=max(maxv,count);
	}
	}
	cout << maxv;

}
