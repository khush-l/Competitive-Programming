#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int INF = 1e18;

int n, d;
set<pair<int, int>> pies[2];
int tasteTime[200001][2], distanceFromZero[200001][2];

int main() {
  freopen("piepie.in", "r", stdin);
  freopen("piepie.out", "w", stdout);

  cin >> n >> d;
  for(int i = 1; i <= 2*n; i++) {
    cin >> tasteTime[i][0] >> tasteTime[i][1];
    if(i > n) pies[0].insert({tasteTime[i][0], i}); // Bessie's pies
    else pies[1].insert({tasteTime[i][1], i}); // Elsie's pies
  }

  // BFS
  queue<pair<int, int>> bfsQueue;
  memset(distanceFromZero, 0x3f, sizeof(distanceFromZero));
  for(int i = 1; i <= 2*n; i++) {
    if(tasteTime[i][0] == 0 && i > n) {
      bfsQueue.push({i, 0});
      distanceFromZero[i][0] = 0;
    } else if(tasteTime[i][1] == 0 && i <= n) {
      bfsQueue.push({i, 1});
      distanceFromZero[i][1] = 0;
    }
  }

  while(!bfsQueue.empty()) {
    int pieIndex, personIndex;
    tie(pieIndex, personIndex) = bfsQueue.front(), bfsQueue.pop();

    // If the other person has this pie, remove it from their set
    if(pies[personIndex].count({tasteTime[pieIndex][personIndex], pieIndex})) {
      pies[personIndex].erase({tasteTime[pieIndex][personIndex], pieIndex});
    }

    // Update distance if shorter path is found
    if(distanceFromZero[pieIndex][personIndex^1] > distanceFromZero[pieIndex][personIndex] + 1) {
      distanceFromZero[pieIndex][personIndex^1] = distanceFromZero[pieIndex][personIndex] + 1;
    }

    // Finding pies reachable by the other person
    vector<pair<int, int>> reachablePies;
    auto it = pies[personIndex^1].lower_bound({tasteTime[pieIndex][personIndex^1] - d, 0});
    while(it != pies[personIndex^1].end() && it->first <= tasteTime[pieIndex][personIndex^1]) {
      reachablePies.push_back(*it);
      if(distanceFromZero[it->second][personIndex^1] > distanceFromZero[pieIndex][personIndex] + 1) {
        bfsQueue.push({it->second, personIndex^1});
        distanceFromZero[it->second][personIndex^1] = distanceFromZero[pieIndex][personIndex] + 1;
      }
      it++;
    }
    for(auto x : reachablePies) {
      pies[personIndex^1].erase(x);
    }
  }

  for(int i = 1; i <= n; i++) {
    cout << (distanceFromZero[i][0] == INF ? -1 : distanceFromZero[i][0]) << endl;
  }
  return 0;
}
