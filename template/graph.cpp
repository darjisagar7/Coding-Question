//undirected gaph without weight
int m = edges.size();
map<int, vector<int>> graph;
for (int i=0; i<m; i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    graph[u].push_back(v);
    graph[v].push_back(u);
}

//undirected gaeraph with weight 
int m = edges.size();
map<int, vector<pair<int, int>>> graph;
for (int i=0; i<m; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];

    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}
