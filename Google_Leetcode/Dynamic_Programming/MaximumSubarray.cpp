# Kadane's algorithm
# https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int max_so_far = INT_MIN;
        int current_max = 0;
        
        for (int i=0;i<nums.size(); i++) {
            current_max += nums[i];
            
            max_so_far = max(max_so_far, current_max);
            
            if (current_max < 0) {
                current_max = 0;
            }
        }
        
        return max_so_far;
    }
};
