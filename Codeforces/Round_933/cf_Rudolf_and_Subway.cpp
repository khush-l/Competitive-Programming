
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int INFINITY = 1e9;

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int vertices, edges;
        cin >> vertices >> edges;

        vector<vector<array<int, 2>>> adjacency_list(vertices);
        vector<int> colors;
        colors.reserve(edges);
        while (edges--) {
            int u, v, color;
            cin >> u >> v >> color;

            --u;
            --v;

            adjacency_list[u].push_back({v, color});
            adjacency_list[v].push_back({u, color});
            colors.push_back(color);
        }

        sort(begin(colors), end(colors));
        colors.erase(unique(begin(colors), end(colors)), end(colors));

        const auto getColorIndex = [&colors](const int color) -> int {
            return distance(begin(colors), lower_bound(begin(colors), end(colors), color));
        };

        int start, end;
        cin >> start >> end;

        --start;
        --end;

        vector<vector<array<int, 2>>> extended_adjacency_list(vertices + colors.size());
        for (int u = 0; u < vertices; ++u) {
            for (auto& [v, color] : adjacency_list[u]) {
                color = getColorIndex(color) + vertices;

                extended_adjacency_list[u].push_back({color, 1});
                extended_adjacency_list[color].push_back({u, 0});
            }
        }

        vector<int> distances(vertices + colors.size(), INFINITY);
        vector<bool> visited(vertices + colors.size());
        deque<int> queue;
        distances[start] = 0;
        queue.push_back(start);

        while (!queue.empty()) {
            const int current_vertex = queue.front();
            queue.pop_front();

            if (visited[current_vertex]) {
                continue;
            }
            visited[current_vertex] = true;

            for (const auto& [neighbor, weight] : extended_adjacency_list[current_vertex]) {
                if (distances[current_vertex] + weight < distances[neighbor]) {
                    distances[neighbor] = distances[current_vertex] + weight;

                    if (weight == 0) {
                        queue.push_front(neighbor);
                    } else {
                        queue.push_back(neighbor);
                    }
                }
            }
        }

        cout << distances[end] << '\n';
    }
    return 0;
}