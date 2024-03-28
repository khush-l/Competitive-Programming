#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isFeasible(int minTime, int* arrivalTimes, int numCows, int numBuses, int capacity) {
    int minArrival = *arrivalTimes, maxArrival, currentCapacity = 0;
    for (int i = 0; i < numCows; i++) {
        maxArrival = *(arrivalTimes + i);
        if (maxArrival - minArrival > minTime || currentCapacity == capacity) {
            numBuses--;
            minArrival = maxArrival;
            currentCapacity = 0;
        }
        if (numBuses == 0) {
            return false;
        }
        currentCapacity++;
    }
    return true;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int numCows, numBuses, capacity, left = -1, right, middle;
    cin >> numCows >> numBuses >> capacity;
    int arrivalTimes[numCows];
    for (int i = 0; i < numCows; i++) {
        cin >> arrivalTimes[i];
    }
    sort(arrivalTimes, arrivalTimes + numCows);
    right = arrivalTimes[numCows - 1] - arrivalTimes[0] + 1;
    while (right - left > 1) {
        middle = (left + right) / 2;
        if (isFeasible(middle, arrivalTimes, numCows, numBuses, capacity)) {
            right = middle;
        } else {
            left = middle;
        }
    }
    cout << right << endl;

    return 0;
}
