class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;
        vector<int> ans;

        for (int num : nums) {
            if(count1 == 0 && candidate2 != num) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0 && candidate1 != num) {
                candidate2 = num;
                count2 = 1;
            } else if (candidate1 == num) {
                count1 += 1;
            } else if (candidate2 == num) {
                count2 += 1;
            } else {
                count1--;
                count2--;
            }

        }

        count1 = 0, count2 = 0;

        for (int i=0;i<nums.size(); i++) {
            if (nums[i] == candidate1) count1++;
            if (nums[i] == candidate2) count2++;
        }

        int mini = (nums.size()/3) + 1;
        if (count1 >= mini) {
            ans.push_back(candidate1);
        }

        if (count2 >= mini) {
            ans.push_back(candidate2);
        }

        return ans;
    }
};
