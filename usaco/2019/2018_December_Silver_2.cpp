#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Cow {
public:
    ll arrivalTime, processingTime;
    int index;
    bool operator < (const Cow &c) const {
        return this->index > c.index; 
    }
};

int main() {
    freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numCows;
    cin >> numCows;
    vector<Cow> cowList(numCows);
    
    for (int i = 0; i < numCows; ++i) {
        cin >> cowList[i].arrivalTime >> cowList[i].processingTime;
        cowList[i].index = i; 
    }

    // Sorting cows based on arrival time
    sort(cowList.begin(), cowList.end(), [](const Cow &a, const Cow &b) {
        return a.arrivalTime == b.arrivalTime ? a.index < b.index : a.arrivalTime < b.arrivalTime;
    });

    // Using priority queue to simulate processing
    priority_queue<Cow, vector<Cow>> waitingQueue;
    int ptr = 0;
    ll currentTime = cowList[0].arrivalTime, maxWaitingTime = 0;
    waitingQueue.push(cowList[ptr++]);
    
    // Processing cows
    while (!waitingQueue.empty()) {
        auto currentCow = waitingQueue.top();
        waitingQueue.pop();
        maxWaitingTime = max(maxWaitingTime, max((ll)0, currentTime - currentCow.arrivalTime));
        currentTime += currentCow.processingTime;
        
        // Adding cows arrived during processing time
        while (ptr < numCows && cowList[ptr].arrivalTime <= currentTime) {
            waitingQueue.push(cowList[ptr++]);
        }
        
        // If no more cows in the queue but more to process
        if (waitingQueue.empty() && ptr < numCows) {
            currentTime = cowList[ptr].arrivalTime;
            waitingQueue.push(cowList[ptr++]);
        }
    }

    cout << maxWaitingTime << endl; 
}
