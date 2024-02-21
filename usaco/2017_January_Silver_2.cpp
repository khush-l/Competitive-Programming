#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)size(x)

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int N;
    cin >> N;

    vector<char> gestures(N);
    for (int i = 0; i < N; ++i) {
        cin >> gestures[i];
    }

    // Create prefix sums for each gesture (H, P, S)
    vector<int> prefixSumH(N + 1), prefixSumP(N + 1), prefixSumS(N + 1);
    for (int i = 0; i < N; ++i) {
        prefixSumH[i + 1] = prefixSumH[i] + (gestures[i] == 'H');
        prefixSumP[i + 1] = prefixSumP[i] + (gestures[i] == 'P');
        prefixSumS[i + 1] = prefixSumS[i] + (gestures[i] == 'S');
    }

    int maxWins = 0;

    // Calculate maximum wins if Bessie switches at each position
    for (int i = 0; i <= N; ++i) {
        int maxSwitched = 0;

        // Calculate wins before the switch
        maxSwitched = max(maxSwitched, prefixSumH[i]);
        maxSwitched = max(maxSwitched, prefixSumP[i]);
        maxSwitched = max(maxSwitched, prefixSumS[i]);

        // Calculate wins after the switch
        int remainingGames = N - i;
        maxSwitched += max(prefixSumH[N] - prefixSumH[i], max(prefixSumP[N] - prefixSumP[i], prefixSumS[N] - prefixSumS[i]));

        maxWins = max(maxWins, maxSwitched);
    }

    cout << maxWins << "\n";
}