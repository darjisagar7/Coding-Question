class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> res;
        int left_bound = lower;
        for(int i=0; i<nums.size(); i++) {
            if (left_bound != nums[i]) res.push_back({left_bound, nums[i]-1});
            left_bound = nums[i] + 1;
        }

        if (left_bound <= upper) res.push_back({left_bound, upper});

        return res;
    }
};
