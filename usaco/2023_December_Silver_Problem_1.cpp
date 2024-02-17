#include <bits/stdc++.h>
using namespace std;

int main() {
    int numCows, numTowers, tolerance;
    cin >> numCows >> numTowers >> tolerance;

    vector<int> cowWeights;
    for (int i = 0; i < numCows; ++i) {
        int weight, amount;
        cin >> weight >> amount;
        for (int j = 0; j < amount; ++j)
            cowWeights.push_back(weight);
    }
    sort(cowWeights.rbegin(), cowWeights.rend());

    int answer = 0;
    deque<double> towers(min(numTowers, static_cast<int>(cowWeights.size())), 1e100);
    for (int cow : cowWeights) {
        if (cow + tolerance <= towers.front()) {
            ++answer;
            towers.pop_front();
            towers.push_back(cow);
        }
    }

    cout << answer << endl;

    return 0;
}
