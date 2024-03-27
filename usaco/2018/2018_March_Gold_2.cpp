#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1e5 + 5;

int num_nodes, num_edges;
vector<int> graph[MAX_NODES / 2], topological_order, adjacency[MAX_NODES];
int in_degree[MAX_NODES];

bool canFinish(int x) {
    int visited_nodes = 0;
    queue<int> q;
    memset(in_degree, 0, sizeof(in_degree));
    
    for (int i = 1; i <= num_nodes; ++i)
        adjacency[i].clear();
    
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < graph[i].size() - 1; ++j) {
            adjacency[graph[i][j]].push_back(graph[i][j + 1]);
            ++in_degree[graph[i][j + 1]];
        }
    }
    
    for (int i = 1; i <= num_nodes; ++i) {
        if (!in_degree[i]) {
            q.push(i);
            ++visited_nodes;
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adjacency[u].size(); ++i) {
            int v = adjacency[u][i];
            --in_degree[v];
            if (!in_degree[v]) {
                q.push(v);
                ++visited_nodes;
            }
        }
    }
    
    return (visited_nodes == num_nodes);
}

void getTopologicalOrder(int x) {
    priority_queue<int, vector<int>, greater<int>> q;
    topological_order.clear();
    memset(in_degree, 0, sizeof(in_degree));
    
    for (int i = 1; i <= num_nodes; ++i)
        adjacency[i].clear();
    
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < graph[i].size() - 1; ++j) {
            adjacency[graph[i][j]].push_back(graph[i][j + 1]);
            ++in_degree[graph[i][j + 1]];
        }
    }
    
    for (int i = 1; i <= num_nodes; ++i) {
        if (!in_degree[i]) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        topological_order.push_back(u);
        for (int i = 0; i < adjacency[u].size(); ++i) {
            int v = adjacency[u][i];
            --in_degree[v];
            if (!in_degree[v]) {
                q.push(v);
            }
        }
    }
}

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout); 

    cin >> num_nodes >> num_edges;
    
    for (int i = 1, t; i <= num_edges; ++i) {
        cin >> t;
        int u;
        while (t--) {
            cin >> u;
            graph[i].push_back(u);
        }
    }
    
    int left = 0, right = num_edges, answer = 0;
    
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (canFinish(mid)) {
            left = mid + 1;
            answer = mid;
        } else {
            right = mid - 1;
        }
    }
    
    getTopologicalOrder(answer);
    
    for (int i = 0; i < num_nodes; ++i) {
        cout << topological_order[i] << " ";
    }
    cout << endl;

}
