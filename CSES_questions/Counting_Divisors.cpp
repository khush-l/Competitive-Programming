#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int N; cin >> N;
	for (int i=0; i<N;i++) {
		int count=0;
		int x;
		cin >> x;
		for (int y=1;y*y<=x;y++) {
			if (x % y == 0) { 
				count += (y * y == x ? 1 : 2); 
				}
		}
		cout << count<<endl;
	}
}
