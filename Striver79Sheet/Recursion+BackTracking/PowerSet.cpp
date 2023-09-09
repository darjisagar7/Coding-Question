class Solution {
public:

    void solve(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        solve(ans, curr, nums, index+1);
        curr.pop_back();
        solve(ans, curr, nums, index+1);
    } 

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(ans, curr, nums, 0);

        return ans;
    }
};
