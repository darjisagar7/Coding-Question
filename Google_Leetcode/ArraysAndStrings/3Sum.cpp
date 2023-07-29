class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        if (n < 3) {
            return {};
        }
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-1; i++) {
            if(i != 0 && nums[i]==nums[i-1]) continue;
            
            int l = i+1;
            int r = n-1;
            int x = nums[i];
            
            while(l<r) {
                if(x + nums[l] + nums[r] == 0) {
                    ans.push_back({x, nums[l], nums[r]});
                    l++;
                    r--;
                    
                    while (l < r && nums[l] == nums[l-1])
                        l++;
                } else if (x + nums[l] + nums[r] > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        
        return ans;
    }
};
