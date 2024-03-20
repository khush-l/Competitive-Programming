#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);

    int num_nodes, start_node;
    cin >> num_nodes >> start_node;

    vector<int> adjacency_list[100005];

    // Reading the graph
    for(int i = 0; i < num_nodes - 1; i++){
        int node_a, node_b;
        cin >> node_a >> node_b;
        adjacency_list[node_a].push_back(node_b);
        adjacency_list[node_b].push_back(node_a);
    }

    bool visited[100005] = {false};
    int distance_from_start[100005];
    int parent_node[100005];
    queue<int> bfs_queue;
    bfs_queue.push(start_node);
    distance_from_start[start_node] = 0;
    vector<int> leaf_nodes;
    visited[start_node] = true;

    // BFS traversal to find the distance from start node to all other nodes
    while (!bfs_queue.empty()) {
        int current_node = bfs_queue.front(); bfs_queue.pop();

        for (int neighbor : adjacency_list[current_node]){
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance_from_start[neighbor] = distance_from_start[current_node] + 1;
                parent_node[neighbor] = current_node;
                bfs_queue.push(neighbor);
            }
        }

        if(adjacency_list[current_node].size() == 1){
            leaf_nodes.push_back(current_node);
        }
    }

    int distance_from_parent[100005];
    for(int i = 0; i < 100005; i++){
        distance_from_parent[i] = 10000005;
    }

    // BFS traversal to find the distance from each leaf node to its parent node
    for(int leaf : leaf_nodes){
        queue<int> leaf_queue;
        distance_from_parent[leaf] = 0;
        leaf_queue.push(leaf);
        while(!leaf_queue.empty()){
            int current_leaf = leaf_queue.front();
            leaf_queue.pop();
            if(parent_node[current_leaf] == start_node){
                break;
            }
            else{
                distance_from_parent[parent_node[current_leaf]] = min(distance_from_parent[parent_node[current_leaf]], distance_from_parent[current_leaf] + 1);
                leaf_queue.push(parent_node[current_leaf]);
            }
        }
    }

    bool visited_inverted[100005] = {false};
    queue<int> bfs_queue_inverted;
    bfs_queue_inverted.push(start_node);
    int answer = 0;
    visited_inverted[start_node] = true;

    // BFS traversal to count the number of nodes where distance from parent is less than or equal to distance from start
    while (!bfs_queue_inverted.empty()) {
        int current_node = bfs_queue_inverted.front(); bfs_queue_inverted.pop();

        if(distance_from_parent[current_node] <= distance_from_start[current_node]){
            answer++;
        }
        else{
            for (int neighbor : adjacency_list[current_node]){
                if (!visited_inverted[neighbor]) {
                    visited_inverted[neighbor] = true;
                    bfs_queue_inverted.push(neighbor);
                }
            }
        }
    }

    cout << answer;
    return 0;
}
