#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    int array_size;
    cin >> array_size;
    vector<pair<int, int>> array_with_indices(array_size);

    for (int i = 0; i < array_size; i++) {
        cin >> array_with_indices[i].first;
        array_with_indices[i].second = i;
    }
    sort(array_with_indices.begin(), array_with_indices.end());

    int max_displacement = 0;
    // Finding maximum displacement for each element after sorting
    for (int i = 0; i < array_size; i++) {
        max_displacement = max(max_displacement, array_with_indices[i].second - i);
    }
    cout << max_displacement + 1 << '\n';
}
