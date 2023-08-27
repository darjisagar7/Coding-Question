# Similar to kadane's algorithm
# https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if (nums.size() == 0) return 0;
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i=1;i<nums.size() ; i++) {
            int curr = nums[i];
            int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));
            min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));

            max_so_far = temp_max;
            result = max(result, max_so_far);

            cout<<max_so_far<<" "<<min_so_far<<" "<<result<<endl;
        }

        return result;
    }
};
