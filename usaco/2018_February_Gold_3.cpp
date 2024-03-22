#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct Object {
    long long len, children, total_children, sum_children;
};

vector<int> child[MAXN];
Object objects[MAXN];
long long solution;
int total_files = 0;

void dfs(int node) {
    if (objects[node].children == 0) {
        return;
    }
    long long total_children = 0, sum_children = 0;
    for (int i : child[node]) {
        if (objects[i].children == 0) {
            ++total_children;
            sum_children += objects[i].len;
        } else {
            dfs(i);
            total_children += objects[i].total_children;
            sum_children += objects[i].sum_children + objects[i].total_children * (objects[i].len + 1); // add directory_name/ to all children
        }
    }
    objects[node].total_children = total_children;
    objects[node].sum_children = sum_children;
}

void solve(int node, long long length) {
    for (int i : child[node]) {
        if (objects[i].children > 0) {
            long long cur = length - (objects[i].len + 1) * objects[i].total_children + (total_files - objects[i].total_children) * 3;
            solution = min(solution, cur);
            solve(i, cur);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);

    int n;
    cin >> n;
    string name;
    int m, a;
    for (int i = 0; i < n; ++i) {
        cin >> name >> m;
        for (int j = 0; j < m; ++j) {
            cin >> a;
            --a;
            child[i].push_back(a);
        }
        if (!m) {
            ++total_files;
        }
        objects[i] = Object{(long long) name.size(), m, 0, 0};
    }
    dfs(0);
    solution = objects[0].sum_children;
    solve(0, solution);
    cout << solution << "\n";
}
