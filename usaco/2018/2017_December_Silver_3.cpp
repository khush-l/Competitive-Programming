#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout); 
    int num_elements;
    cin >> num_elements;

    vector<int> permutation(num_elements), count(num_elements);
    for (int i = 0; i < num_elements; i++)
        cin >> permutation[i], permutation[i]--, count[permutation[i]]++;

    // Count the number of cycles
    int answer = num_elements;
    queue<int> zero_degree_elements;
    for (int i = 0; i < num_elements; i++) {
        if (count[i] == 0) {
            zero_degree_elements.push(i);
            answer--;
        }
    }

    // Traverse through cycles
    while (!zero_degree_elements.empty()) {
        int current = zero_degree_elements.front();
        zero_degree_elements.pop();
        if (--count[permutation[current]] == 0) {
            zero_degree_elements.push(permutation[current]);
            answer--;
        }
    }
    cout << answer << endl;

    return 0;
}
