#include <bits/stdc++.h>

using namespace std;

int precedence(char ch) {
    if( ch == '^' ) {
        return 3;
    } else if( ch == '*' || ch == '/') {
        return 2;
    } else if ( ch == '+' || ch == '-' ) {
        return 1;
    } else {
        return -1;
    }
}

void infixToPostfix(string str) {
    string ans="";
    
    int n=str.size();
    stack<char> st;
    st.push('N');
    
    for(int i=0;i<n;i++) {
        if( (str[i] >= 'a' && str[i] <='z') || (str[i] >= 'A' && str[i] <='Z')) {
            ans += str[i];
        } else if( str[i] == '(' ) {
            st.push(str[i]);
        } else if( str[i] == ')' ) {
            while(st.top() != 'N' && st.top() != '(' ) {
                ans += st.top();
                st.pop();
            }
            if(st.top() == '(' ) {
                st.pop();
            }
        } else {
            while( st.top() != 'N' && precedence(str[i]) <= precedence(st.top()) ) {
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    
    while( st.top() != 'N' ) {
        ans += st.top();
        st.pop();
    }
    
    cout<<ans<<"\n";
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
