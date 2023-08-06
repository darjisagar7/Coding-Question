class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int n = s.length();
        int left = 0;
        int right = 0;
        int ans = 0;
        map<char, int> map;
        
        if (n < 3) {
            return n;
        }
        
        while (right < n) {
            map[s[right]] = right;
            right++;
            if (map.size() == 3) {
                int del_idx = INT_MAX;
                for (pair<char, int> element: map) {
                    del_idx = min(del_idx, element.second);
                }
                
                map.erase(s[del_idx]);
                left = del_idx + 1;
            }
            
            ans = max(ans, right - left);
        }
        
        return ans;
    }
};
