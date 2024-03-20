#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int numPoints;
    map<int,int> slopeChanges; // slopeChanges[t] denotes the change in slope of f(y) when y=t
     
    long long currentDistance = 0, currentSlope = 0, currentY = -2000000000;

    cin >> numPoints;
    for (int i = 0; i < numPoints; i++) {
        int source, destination;
        cin >> source >> destination;
        currentDistance += abs(source - destination);
        
        // Adjust slope change breakpoints
        if (abs(source) > abs(source - destination)) continue;
        slopeChanges[destination] += 2;
        if (source < destination && source < 0) {
            slopeChanges[0]--;
            slopeChanges[2 * destination]--;
        }
        if (source < destination && source >= 0) {
            slopeChanges[2 * destination - 2 * source]--;
            slopeChanges[2 * source]--;
        }
        if (source >= destination && source < 0) {
            slopeChanges[2 * destination - 2 * source]--;
            slopeChanges[2 * source]--;
        }
        if (source >= destination && source >= 0) {
            slopeChanges[0]--;
            slopeChanges[2 * destination]--;
        }
    }      

    // Traverse y forward and apply slope changes to trace out f(y), keeping track of min
    long long minDistance = currentDistance;
    for (auto point : slopeChanges) {
        int newY = point.first, deltaSlope = point.second;
        currentDistance += currentSlope * (newY - currentY);
        currentY = newY;
        currentSlope += deltaSlope;
        minDistance = min(minDistance, currentDistance);
    }

    cout << minDistance << "\n";
}
