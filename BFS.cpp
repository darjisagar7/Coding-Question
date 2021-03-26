#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void BFS(vector<int> adj[], int V, int src) {
    queue<int> q;
    vector<bool> visited(V, false);
    
    q.push(src);
    visited[src] = true;
    
    while(!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        
        for(auto x: adj[u]) {
            if(!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main()
{
    int V = 4;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);
    
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    BFS(adj, V, 2);
    
    return 0;
}
