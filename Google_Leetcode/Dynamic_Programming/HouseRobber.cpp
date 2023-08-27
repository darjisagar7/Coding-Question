# https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        int robNext, robNextPlusOne;

        robNext = nums[n-1];
        robNextPlusOne = 0;

        for (int i=n-2; i>=0; --i) {
            int current = max(robNext, robNextPlusOne + nums[i]);

            robNextPlusOne = robNext;
            robNext = current;
        }

        return robNext;
    }
};
