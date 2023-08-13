class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString;
        int k = 0;

        for (auto ch: s) {
            if (isdigit(ch)) {
                k = k * 10 + ch - '0';
            } else if (ch == '[') {
                countStack.push(k);
                k = 0;

                stringStack.push(currentString);
                currentString = "";
            } else if (ch == ']') {

                string decodeString = stringStack.top();
                stringStack.pop();
                
                for (int i = countStack.top(); i>0; i--) {
                    decodeString = decodeString + currentString;
                }

                countStack.pop();

                currentString = decodeString;                
            } else {
                currentString += ch;
            }
        }


        return currentString;
    }
};
