#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100001;
int N, fenwickTree[MAX_N];

void update(int idx) { // Updates the Fenwick tree
    for (; idx <= N; idx += (idx & -idx))
        fenwickTree[idx]++;
}

int query(int idx) { // Calculates prefix sum
    int sum = 0;
    for (; idx > 0; idx -= (idx & -idx))
        sum += fenwickTree[idx];
    return sum;
}

int main() {
    freopen("sort.in", "r", stdin); 
    freopen("sort.out", "w", stdout);

    int maxNonOverlappingIntervals = 1; 
    cin >> N;
    pair<int, int> arrayElements[MAX_N];

    for (int i = 1; i <= N; i++) {
        int element;
        cin >> element;
        arrayElements[i] = make_pair(element, i);
    }
    sort(arrayElements + 1, arrayElements + N + 1);

    for (int i = 1; i <= N - 1; i++) {
        update(arrayElements[i].second);
        maxNonOverlappingIntervals = max(maxNonOverlappingIntervals, i - query(i));
    }
    cout << maxNonOverlappingIntervals << "\n";
    return 0;
}
