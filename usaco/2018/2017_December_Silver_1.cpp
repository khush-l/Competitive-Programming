#include <bits/stdc++.h>
using namespace std;

const int MAX_STUDENTS = 100000;

long long studentScores[MAX_STUDENTS + 1];
long long suffixSum[MAX_STUDENTS + 1];
long long suffixMin[MAX_STUDENTS + 1];
long long bestNumerator, bestDenominator;

int main() {
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);

    int totalStudents;
    cin >> totalStudents;

    // Reading student scores
    for (int i = 1; i <= totalStudents; i++)
        cin >> studentScores[i];

    suffixSum[totalStudents] = studentScores[totalStudents];
    suffixMin[totalStudents] = studentScores[totalStudents];

    // Calculating suffix sums and suffix minimums
    for (int i = totalStudents - 1; i >= 1; i--) {
        suffixSum[i] = suffixSum[i + 1] + studentScores[i];
        suffixMin[i] = min(suffixMin[i + 1], studentScores[i]);
    }

    bestNumerator = 0;
    bestDenominator = 1;

    // Finding the best numerator and denominator
    for (int i = 1; i <= totalStudents - 2; i++) {
        if ((suffixSum[i + 1] - suffixMin[i + 1]) * bestDenominator > bestNumerator * (totalStudents - i - 1)) {
            bestNumerator = suffixSum[i + 1] - suffixMin[i + 1];
            bestDenominator = totalStudents - i - 1;
        }
    }

    // Printing out indices with optimal scores
    for (int i = 1; i <= totalStudents - 2; i++) {
        if ((suffixSum[i + 1] - suffixMin[i + 1]) * bestDenominator == bestNumerator * (totalStudents - i - 1)) {
            cout << i << "\n";
        }
    }

    return 0;
}
