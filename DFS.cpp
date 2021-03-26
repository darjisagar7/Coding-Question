#include <bits/stdc++.h>

using namespace std;

void addEdge(map<int, vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

void DFS(map<int, vector<int>>& adj, map<int, bool>& visited, int v) {
    
    visited[v] = true;
    
    cout << v << " ";
    
    for (auto x: adj[v]) {
        if (!visited[x])
            DFS(adj, visited, x);
    }
}

int main() {

    map<int, vector<int>> adj;
    map<int, bool> visited;

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 9);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 9, 3);
    
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    
    DFS(adj, visited, 2);
    
    return 0;
}
