#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_NODES = 50'000;
vector<pair<int, int>> adjacency[MAX_NODES];
int distance_without_haybales[MAX_NODES], distance_with_haybales[MAX_NODES];
vector<pair<int, int>> haybales;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);

    int num_nodes, num_edges, num_haybales;
    cin >> num_nodes >> num_edges >> num_haybales;

    // Reading the graph edges
    for (int i = 0; i < num_edges; ++i) {
        int u, v, time;
        cin >> u >> v >> time;
        --u; --v; // 0-based indexing
        adjacency[u].push_back({v, time});
        adjacency[v].push_back({u, time}); // Undirected graph
    }

    // Reading the haybales
    for (int i = 0; i < num_haybales; ++i) {
        int index, deliciousness;
        cin >> index >> deliciousness;
        --index; // 0-based indexing
        haybales.push_back({index, deliciousness});
    }

    // Dijkstra's Algorithm without considering haybales
    fill(distance_without_haybales, distance_without_haybales + num_nodes, 1e9);
    distance_without_haybales[num_nodes - 1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, num_nodes - 1});
    while (!pq.empty()) {
        auto [cur_dist, node] = pq.top();
        pq.pop();
        if (cur_dist != distance_without_haybales[node]) continue;
        for (auto neighbor : adjacency[node]) {
            int neighbor_node = neighbor.first;
            int neighbor_time = neighbor.second;
            if (cur_dist + neighbor_time < distance_without_haybales[neighbor_node]) {
                distance_without_haybales[neighbor_node] = cur_dist + neighbor_time;
                pq.push({distance_without_haybales[neighbor_node], neighbor_node});
            }
        }
    }

    // Updating distances considering the deliciousness of haybales
    fill(distance_with_haybales, distance_with_haybales + num_nodes, 1e9);
    for (auto haybale : haybales) {
        int haybale_index = haybale.first;
        int deliciousness = haybale.second;
        distance_with_haybales[haybale_index] = min(distance_with_haybales[haybale_index], distance_without_haybales[haybale_index] - deliciousness);
        pq.push({distance_with_haybales[haybale_index], haybale_index});
    }

    // Dijkstra's Algorithm considering the deliciousness of haybales
    while (!pq.empty()) {
        auto [cur_dist, node] = pq.top();
        pq.pop();
        if (cur_dist != distance_with_haybales[node]) continue;
        for (auto neighbor : adjacency[node]) {
            int neighbor_node = neighbor.first;
            int neighbor_time = neighbor.second;
            if (cur_dist + neighbor_time < distance_with_haybales[neighbor_node]) {
                distance_with_haybales[neighbor_node] = cur_dist + neighbor_time;
                pq.push({distance_with_haybales[neighbor_node], neighbor_node});
            }
        }
    }

    for (int i = 0; i < num_nodes - 1; ++i) {
        if (distance_with_haybales[i] <= distance_without_haybales[i]) {
            cout << 1 << '\n'; 
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
