#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm> 
#include <unordered_set>
using namespace std;
int calculateTotalPoints(const vector<string>& cards) {
    int totalPoints = 0;
    for (const string& card : cards) {
        vector<int> winningNumbers;
        vector<int> yourNumbers;
        istringstream iss(card);
        int num;
        while (iss >> num && iss.peek() != '|') {
            winningNumbers.push_back(num);
        }
        iss.ignore();
        while (iss >> num) {
            yourNumbers.push_back(num);
        }
        int roundPoints = 0;
        int multiplier = 1;

        for (const int& num : yourNumbers) {
            if (find(winningNumbers.begin(), winningNumbers.end(), num) != winningNumbers.end()) {
                roundPoints += multiplier;
                multiplier *= 2;
            }
        }
        totalPoints += roundPoints;
    }
    return totalPoints;
}
int main() {
    vector<string> cards;
    string line;
    while (getline(cin, line)) {
        cards.push_back(line);
    }
    int totalPoints = calculateTotalPoints(cards);
    cout << totalPoints << endl;
    return 0;
}
