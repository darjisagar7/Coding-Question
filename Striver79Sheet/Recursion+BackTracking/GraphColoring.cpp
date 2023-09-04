#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(int node, int i, int N, bool graph[101][101], int color[]) {

    for (int k=0;k<N; k++) {
        if (k != node && graph[k][node] == 1 && color[k] == i) {
            return false;
        }
    }
    return true;

}

bool solve(int node, bool graph[101][101], int color[], int m, int N) {

    if (node == N) {
        return true;
    }

    for (int i=1;i<=m;i++) {
        if (isSafe(node, i, N, graph, color)) {
            color[node] = i;
            if (solve(node+1, graph, color, m, N)) {
                return true;
            }
            color[node] = 0;
        }
    }

    return false;

}

bool graphColoring(bool graph[101][101], int m, int N) {
    int color[N];

    for (int i=0;i<N;i++) {
        color[i] = 0;
    }

    if (solve(0, graph, color, m, N)) {
        return true;
    } else {
        return false;
    }
}

int main() {
  int N = 4;
  int m = 3;

  bool graph[101][101];
  memset(graph, false, sizeof graph);

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  cout << graphColoring(graph, m, N);

}
