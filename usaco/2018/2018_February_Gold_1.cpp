#include <bits/stdc++.h>
using namespace std;

struct Boot {
  int snowDepth, maxStep, index;
  bool operator< (const Boot& other) {
    return snowDepth > other.snowDepth;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("snowboots.in", "r", stdin);
  freopen("snowboots.out", "w", stdout);

  int numTiles, numBoots;
  cin >> numTiles >> numBoots;

  vector<int> tileDepth(numTiles);
  for (auto& depth : tileDepth)
    cin >> depth;

  // Generate indices for tiles
  vector<int> tileIndices(numTiles - 2);
  iota(tileIndices.begin(), tileIndices.end(), 1);

  // Sorting tiles based on depth
  sort(tileIndices.begin(), tileIndices.end(), [&tileDepth](const int& left, const int& right) {
    return tileDepth[left] > tileDepth[right];
  });

  vector<Boot> boots(numBoots);
  for (int i = 0; i < numBoots; ++i) {
    cin >> boots[i].snowDepth >> boots[i].maxStep;
    boots[i].index = i;
  }
  sort(boots.begin(), boots.end());

  set<int> availableTiles;
  for (int i = 0; i < numTiles; ++i)
    availableTiles.insert(availableTiles.end(), i);

  int tileIndex = 0, requiredDistance = 0;
  vector<bool> result(numBoots);

  for (const auto& boot : boots) {
    while (tileIndex < numTiles - 2 && tileDepth[tileIndices[tileIndex]] > boot.snowDepth) {
      auto it = availableTiles.find(tileIndices[tileIndex]);
      requiredDistance = max(requiredDistance, *next(it) - *prev(it));
      availableTiles.erase(it);
      tileIndex++;
    }
    result[boot.index] = (boot.maxStep >= requiredDistance);
  }

  for (const auto& res : result)
    cout << res << '\n';

}
