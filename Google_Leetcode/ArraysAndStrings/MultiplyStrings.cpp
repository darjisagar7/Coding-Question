class Solution {
public:
    string multiply(string num1, string num2) {
      if(num1 == "0" || num2 == "0"){
            return "0";
        }
        int s1 = num1.length(), s2 = num2.length();
        vector<int>　ans(s1+s2,0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<s1;i++){
            for(int j=0;j<s2;j++){
                ans[i+j] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        for(int i=0;i<s1+s2-1;i++){
            ans[i+1] += ans[i]/10;
            ans[i] %= 10;
        }
        while(!ans[ans.size()-1]){
            ans.pop_back();
        }
        string s = "";
        for(int i=ans.size()-1;i>=0;i--){
            s += to_string(ans[i]);
        }
        return s;
    }
};
