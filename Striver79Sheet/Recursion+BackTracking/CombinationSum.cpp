class Solution {
public:
    void solve(int index, int target, vector<int>& v, vector<vector<int>>& ans, vector<int>& curr) {

        if (index == v.size()) { 
            if (target == 0) {
                ans.push_back(curr);
            }
            return;
        }
        
        if (target - v[index] >= 0) {
            curr.push_back(v[index]);
            solve(index, target-v[index], v, ans, curr);
            curr.pop_back();
        }

        solve(index+1, target, v, ans, curr);
    }

    vector < vector < int > > combinationSum(vector<int>& v, int target) {
        vector< vector< int > > ans;
        vector<int> curr;

        solve(0, target, v, ans, curr);

        return ans;
    }
};
