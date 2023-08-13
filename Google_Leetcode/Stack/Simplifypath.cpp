class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n=path.size();
        for(int i=0;i<n;i++){
            if(path[i]=='/'){
                continue;
            }
            
            string ans="";
            
            while(i<n && path[i]!='/'){
                ans+=path[i];
                i++;
            }
            i--;
            
            if(ans=="."){
                continue;
            }
            
            if(ans==".."){
                if(!st.empty()){
                    st.pop();
                }
                continue;
            }
            
            st.push(ans);
        }
        
        if(st.empty()){
            return "/";
        }
        
        string ans="";
        
        while(!st.empty()){
            ans="/" + st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};
