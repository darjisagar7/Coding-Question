class Solution {
public:
    void genPath(int n, string str, vector<string>& vec, int left, int right) {
        if (str.size() == 2*n) {
            vec.push_back(str);
            return;
        }
        
        if (left < n) {
            genPath(n, str + "(", vec, left + 1, right);
        }
        
        if (left > right) {
            genPath(n, str + ")", vec, left, right +1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        genPath(n, "", ans, 0, 0);
        
        return ans;
    }
};
