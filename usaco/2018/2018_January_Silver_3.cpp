#include <bits/stdc++.h>
using namespace std;

bool visited[5005];
int n, q;
vector<vector<pair<int,int>>> adjList;
int answer = 0;

void dfs(int node, int relevance){
	if(visited[node]) return;

	visited[node] = true;
	for(auto neighbor : adjList[node]){
		if(visited[neighbor.first] || neighbor.second < relevance) continue;
		answer++;
		dfs(neighbor.first, relevance);
	}
}

int main() {
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

	cin >> n >> q;
	adjList.resize(n);

	for(int i = 0; i < n - 1; i++){
		int u, v, c;
		cin >> u >> v >> c;
		adjList[--u].emplace_back(make_pair(--v, c));
		adjList[v].emplace_back(make_pair(u, c));
	}

	for(int i = 0; i < q; i++){
		int relevance, startingNode;
		cin >> relevance >> startingNode;

		memset(visited, 0, sizeof(visited));
		answer = 0;

		dfs(--startingNode, relevance);
		cout << answer <<"\n";
	}
}
