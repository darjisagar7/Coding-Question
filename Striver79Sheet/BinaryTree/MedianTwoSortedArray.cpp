// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        int n1 = num1.size();
        int n2 = num2.size();

        if (n1>n2) {
            return findMedianSortedArrays(num2, num1);
        }

        int low = 0;
        int high = n1;

        while (low <= high) {
            int cut1 = (low+high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int left1 = (cut1 == 0) ? -1e7 : num1[cut1-1];
            int left2 = (cut2 == 0) ? -1e7 : num2[cut2-1];
            int right1 = (cut1 == n1) ? 1e7 : num1[cut1];
            int right2 = (cut2 == n2) ? 1e7 : num2[cut2];

            if (left1 <= right2 && left2 <= right1) {
                if ((n1+n2)%2 == 1) {
                    return max(left1, left2);
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            }

            if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 +1;
            }
        }

        return 0.0;
    }
};
