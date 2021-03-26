/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> iPair;

void addEdge(vector<iPair> adj[], int u, int v, int wgt) {
    adj[u].push_back({v, wgt});
    adj[v].push_back({u, wgt});
}

void shortestPath(vector<iPair> adj[], int V, int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    
    vector<int> dist(V, INT_MAX);
    
    pq.push({0, src});
    dist[src] = 0;
    
    while(!pq.empty()) {
        
        int u = pq.top().second;
        pq.pop();
        
        for(auto x: adj[u]) {
            int v = x.first;
            int weight = x.second;
            
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    int V = 9;
    vector<iPair> adj[V];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 1);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
    
    shortestPath(adj, V, 0);

    return 0;
}
