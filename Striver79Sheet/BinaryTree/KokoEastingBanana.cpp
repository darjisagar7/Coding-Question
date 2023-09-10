class Solution {
public:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        //find the maximum:
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    long int calculateTotalHours(vector<int> &v, int hourly) {
        long int totalH = 0;
        int n = v.size();
        //find total hours:
        for (auto elem: v) {
            totalH += ceil((double)(elem) / (double)(hourly));
        }
        return totalH;
    }

    int minEatingSpeed(vector<int> v, int h) {
        int low = 1, high = findMax(v);

        //apply binary search:
        while (low <= high) {
            int mid = (low + high) / 2;
            long int totalH = calculateTotalHours(v, mid);
            if (totalH <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
