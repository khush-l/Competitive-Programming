#include <bits/stdc++.h>
using namespace std;

#define MAX_VIDEOS 200000

int numVideos, numQueries; 
int parent[MAX_VIDEOS];
int numRelevant[MAX_VIDEOS]; 

int findRoot(int video) {
    if (parent[video] == video) {
        return video;
    }
    parent[video] = findRoot(parent[video]); // Path compression
    return parent[video];
}

void merge(int videoA, int videoB) {
    videoA = findRoot(videoA);
    videoB = findRoot(videoB);
    parent[videoB] = videoA;
    numRelevant[videoA] += numRelevant[videoB];
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    cin >> numVideos >> numQueries;

    map<int, vector<pair<int, int>>> edgeWeights; // Map weight to connections

    for (int i = 0; i < numVideos - 1; i++) { // Edges
        int p, q, r;
        cin >> p >> q >> r;
        edgeWeights[r].push_back({p, q});
    }

    for (int i = 1; i <= numVideos; i++) {
        parent[i] = i;
        numRelevant[i] = 1;
    }

    vector<vector<int>> queries(numQueries);

    for (int i = 0; i < numQueries; i++) {
        int relevance, video;
        cin >> relevance >> video;
        queries[i] = {relevance, video, i}; // Relevance, video, original index
    }

    vector<int> answers(numQueries);

    sort(queries.begin(), queries.end());

    auto it = edgeWeights.rbegin();

    for (int i = numQueries - 1; i >= 0; i--) {
        while (it != edgeWeights.rend() && it->first >= queries[i][0]) {
            // Merge all edges with weight >= the weight of current query
            for (auto edge : it->second) {
                merge(edge.first, edge.second);
            }
            it++;
        }

        answers[queries[i][2]] = numRelevant[findRoot(queries[i][1])] - 1;
    }

    for (auto answer : answers) {
        cout << answer << endl;
    }

    return 0;
}
