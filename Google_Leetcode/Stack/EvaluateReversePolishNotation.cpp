class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> numStack;
        int res = 0;
        string operations = "+-*/";

        for (auto token: tokens) {
            size_t found =  operations.find(token);
            if (found == string::npos) {
                numStack.push(stoi(token));
            } else {
                int b = numStack.top();
                numStack.pop();
                int a = numStack.top();
                numStack.pop();
                if (token == "+") {
                    res = a + b;
                } else if (token == "-") {
                    res = a - b;
                } else if (token == "*") {
                    res = a * b;
                } else if (token == "/") {
                    res = a / b;
                } 

                numStack.push(res);
            }
        } 

        return numStack.top();
        
    }
};
