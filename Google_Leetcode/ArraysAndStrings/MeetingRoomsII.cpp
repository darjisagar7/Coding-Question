class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        vector<int> start;
        vector<int> end;
        int n = intervals.size();

        for (int i=0; i< n; i++) {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int s_ptr = 0;
        int e_ptr = 0;
        int ans = 0;
        
        while (s_ptr < n) {

            if (start[s_ptr] >= end[e_ptr]) {
                ans -= 1;
                e_ptr += 1;
            }

            ans += 1;
            s_ptr += 1;
        }

        return ans;
    }
};
