class Solution {
public:
    string decodeString(string s) {
        int i=0;
        return decodeString(s, i);
    }

    string decodeString(const string& s, int& k) {
        string res;
        while (k < s.length() && s[k] != ']') {
            if (!isdigit(s[k])) {
                res += s[k];
                k++;
            } else {
                int num=0;

                while (k <s.length() && isdigit(s[k])) {
                    num = num * 10 + s[k] - '0';
                    k++;
                }

                k++;

                string decodedString = decodeString(s, k);

                k++;

                while (num-- > 0) {
                    res += decodedString;
                }
            }
        }
        return res;
    }
};
