#include <bits/stdc++.h>
using namespace std;

int forest[1001][1001];
int prefix[1001][1001];
int main() {
	int N;
	int Q;
	cin >> N >> Q;
    for (int j = 1; j <= N; j++) {
	    for (int i = 1; i <= N; i++) {
            char val;
		    cin >> val;
            if (val == '*') {
                forest[j][i]=1;
        }
        }
    }
    for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			prefix[i][j] = forest[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
		}
	}
    for (int query = 0; query < Q; query++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int tree_count = prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1];
        cout << tree_count << endl;
    }
}
