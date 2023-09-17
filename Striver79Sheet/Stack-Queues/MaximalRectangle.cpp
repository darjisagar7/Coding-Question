// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:

    int maxArea(vector<int> vec) {
        int maxA = 0;
        int n = vec.size();
        stack<int> st;

        for (int i=0; i<=n; i++) {
            while(!st.empty() && (i==n || vec[st.top()] >= vec[i])) {
                int height = vec[st.top()];
                st.pop();
                int width = i;
                if (!st.empty()) {
                    width = i - st.top() - 1;
                }

                maxA = max(maxA, height * width);
            }
            st.push(i);
        }

        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> vec(m,0);

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (matrix[i][j] == '1') {
                    vec[j] ++;
                } else {
                    vec[j] = 0;
                }
            }
            cout<<maxArea(vec);
            ans = max(ans, maxArea(vec));
        }

        return ans;
    }
};
