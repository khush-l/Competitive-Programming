#include <bits/stdc++.h>
using namespace std;

struct Lifeguard {
    int start_time, end_time, original_index;
    bool operator < (Lifeguard& other) {
        return start_time < other.start_time;
    }
};

bool compareEndTime(Lifeguard a, Lifeguard b) {
    return a.end_time > b.end_time;
}

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int num_lifeguards;
    cin >> num_lifeguards;

    Lifeguard lifeguards[num_lifeguards], sorted_lifeguards[num_lifeguards];

    for (int i = 0; i < num_lifeguards; i++) {
        cin >> lifeguards[i].start_time >> lifeguards[i].end_time;
        lifeguards[i].original_index = i;
    }
    sort(lifeguards, lifeguards + num_lifeguards);

    int total_covered_time = 0, last_end_time = 0;

    // Calculate total covered time and adjust start times
    for (int i = 0; i < num_lifeguards; i++) {
        sorted_lifeguards[lifeguards[i].original_index].start_time = max(lifeguards[i].start_time, last_end_time);
        total_covered_time += max(0, lifeguards[i].end_time - max(lifeguards[i].start_time, last_end_time));
        last_end_time = max(last_end_time, lifeguards[i].end_time);
    }

    // Sort lifeguards based on end time
    sort(lifeguards, lifeguards + num_lifeguards, compareEndTime);

    last_end_time = INT_MAX;

    // Adjust end times
    for (int i = 0; i < num_lifeguards; i++) {
        sorted_lifeguards[lifeguards[i].original_index].end_time = min(lifeguards[i].end_time, last_end_time);
        last_end_time = min(last_end_time, lifeguards[i].start_time);
    }

    int min_uncovered_time = INT_MAX;

    // Calculate minimum uncovered time
    for (int i = 0; i < num_lifeguards; i++) {
        min_uncovered_time = min(min_uncovered_time, max(0, sorted_lifeguards[i].end_time - sorted_lifeguards[i].start_time));
    }

    cout << total_covered_time - min_uncovered_time << endl;
}
