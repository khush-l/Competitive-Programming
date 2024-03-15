#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

int N;

void move(int from, int to, int depth) {
    if (depth == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }

    int other = 6 - from - to;
    move(from, other, depth - 1);
    cout << from << ' ' << to << '\n';
    move(other, to, depth - 1);
}

int main() {
    cin >> N;
    cout << (1 << N) - 1 << '\n';
    move(1, 3, N);
}