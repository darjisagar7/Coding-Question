class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        
        for (auto prerequisite: prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        int nodeVisited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            nodeVisited++;

            for (auto& neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                    ans.push_back(neighbor);
                }
            }
        }

        if (nodeVisited != numCourses) {
            ans.clear();
        }

        return ans;
    }
};
