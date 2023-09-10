class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0;
        int high = nums.size()-1;

        while(low<=high) {
            int mid = (low + high)/ 2;

            if (nums[mid] == target) {
                return true;
            } else if (nums[low] == target) {
                return true;
            } else if (nums[high] == target) {
                return true;
            } else if (target > nums[mid] && target < nums[high]) {
                low = mid + 1;
            } else if (target < nums[mid] && target > nums[low]) {
                high = mid - 1;
            } else {
                low++;
                high--;
            }
        }

        return false;
    }
};
