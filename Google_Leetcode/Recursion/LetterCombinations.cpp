class Solution {
public:
    
    map<char, string> phone;
    
    void letterComb(vector<string>& ans, string digits, int n, string str) {
        if (n == digits.size()) {
            ans.push_back(str);
        }
        
        if (phone.find(digits[n]) != phone.end()) {
            for (auto it: phone[digits[n]]) {
                letterComb(ans, digits, n+1, str+it);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pqrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";
        
        vector<string> ans;
        
        if (digits.size() > 0) letterComb(ans, digits, 0, "");
        
        return ans;
    }
};
