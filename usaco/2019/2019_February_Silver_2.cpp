#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1001;

int main() {
      freopen("paintbarn.in", "r", stdin);
  freopen("paintbarn.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    vector<vector<int>> barn(MAX_SIZE, vector<int>(MAX_SIZE, 0));
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        barn[x1][y1]++;
        barn[x1][y2]--;
        barn[x2][y1]--;
        barn[x2][y2]++;
    }

    for (int x = 0; x < MAX_SIZE; ++x) {
        for (int y = 1; y < MAX_SIZE; ++y) {
            barn[x][y] += barn[x][y - 1];
        }
    }

    for (int y = 0; y < MAX_SIZE; ++y) {
        for (int x = 1; x < MAX_SIZE; ++x) {
            barn[x][y] += barn[x - 1][y];
        }
    }

    int coveredArea = 0;
    for (int x = 0; x < MAX_SIZE; ++x) {
        for (int y = 0; y < MAX_SIZE; ++y) {
            if (barn[x][y] == K) {
                coveredArea++;
            }
        }
    }

    cout << coveredArea << endl;

    return 0;
}
