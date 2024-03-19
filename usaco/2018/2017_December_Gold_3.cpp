#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 1;

struct Dish {
    int flavor, spice;
};

int main() {
    ios_base::sync_with_stdio(false);
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<Dish> dishes(n);
    for (int i = 0; i < n; ++i)
        cin >> dishes[i].flavor >> dishes[i].spice;

    long long minSpice = LLONG_MAX;
    long long totalFlavor = 0;
    multiset<int> windowSpice;

    for (int left = 0, right = 0; left < n && right < n;) {
        if (totalFlavor < m) { // If total flavor is less than the required
            totalFlavor += dishes[right].flavor;
            windowSpice.insert(dishes[right].spice);
            ++right; 
        }
        if (totalFlavor >= m) { // If total flavor exceeds or equals the required
            minSpice = min(minSpice, (long long)*windowSpice.rbegin());
            totalFlavor += dishes[right].flavor;
            windowSpice.insert(dishes[right].spice);
            ++right; 
        }
        if (totalFlavor - dishes[left].flavor >= m) { // If we can subtract flavor from the left
            totalFlavor -= dishes[left].flavor;
            windowSpice.erase(windowSpice.find(dishes[left].spice));
            minSpice = min(minSpice, (long long)*windowSpice.rbegin());
            ++left; 
        }
    }

    cout << minSpice << endl;

    return 0;
}
