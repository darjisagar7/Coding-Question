class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int currentMax = 0;

        for (int i=0;i<nums.size(); i++) {
            currentMax += nums[i];
            if (currentMax >= ans) {
                ans = max(ans, currentMax);
            } 

            if (currentMax < 0) {
                currentMax =0;
            }
        }

        return ans;
    }
};
