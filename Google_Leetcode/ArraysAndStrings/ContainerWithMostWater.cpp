class Solution {
public:
    int maxArea(vector<int>& height) {

        int l = 0, r = height.size()-1, max_area = 0, area = 0;

        while (l < r) {
            area = min(height[l], height[r]) * (r-l);

            if (area > max_area) {
                max_area = area;
            }

            if (height[l] > height[r]) {
                r--;
            } else {
                l++;
            }
        }

        return max_area;
        
    }
};
