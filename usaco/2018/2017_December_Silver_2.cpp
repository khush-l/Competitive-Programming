#include <bits/stdc++.h>
using namespace std;

struct Measurement {
    int day, id, change;
    bool operator<(const Measurement& m) const {
        return day < m.day;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int numMeasurements, initialGallons;
    cin >> numMeasurements >> initialGallons;

    vector<Measurement> measurements(numMeasurements);
    for (auto& m : measurements) 
        cin >> m.day >> m.id >> m.change;

    sort(measurements.begin(), measurements.end());

    map<int, int> currentAmount, cowCount;
    cowCount[initialGallons] = numMeasurements + 2;

    int changes = 0;
    for (auto& m : measurements) {
        // Initialize cow's initial amount 
        if (!currentAmount.count(m.id))
            currentAmount[m.id] = initialGallons;

        int previousAmount = currentAmount[m.id];
        currentAmount[m.id] += m.change;

        auto [highestAmount, countHighest] = *cowCount.rbegin();
        cowCount[currentAmount[m.id]]++;

        // Decrease count of previous amount
        if (--cowCount[previousAmount] == 0)
            cowCount.erase(previousAmount);

        auto [newHighestAmount, newCountHighest] = *cowCount.rbegin();
        if (countHighest != newCountHighest || 
            (highestAmount != newHighestAmount && !(previousAmount == highestAmount && currentAmount[m.id] == newHighestAmount && newCountHighest == 1)))
            changes++;
    }
    
    cout << changes << '\n';
}
