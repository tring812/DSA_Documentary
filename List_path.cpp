#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// adj la danh sach ke (da duoc sap xep tang dan trong main).
// Liet ke tat ca duong di don tu a den b theo thu tu DFS.
// In "KHONG CO" neu khong co duong di nao.

void dfs(int u, int target, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& path, bool& hasPath) {
    visited[u] = true;
    path.push_back(u);

    if (u == target) {
        hasPath = true;
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << " ";
        }
        cout << "\n";
    } else{
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, target, adj, visited, path, hasPath);
            }
        }
    }

    path.pop_back();
    visited[u] = false;
}

void listPaths(const vector<vector<int>>& adj, int n, int a, int b) {
    vector<bool> visited(n, false);
    vector<int> path;
    bool hasPath = false;

    dfs(a, b, adj, visited, path, hasPath);
    if (!hasPath) {
        cout << "KHONG CO\n";
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    int a, b;
    cin >> a >> b;

    listPaths(adj, n, a, b);

    return 0;
}
