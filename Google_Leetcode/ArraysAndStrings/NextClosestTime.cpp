class Solution {
public:
    string nextClosestTime(string time) {
        
        int minutes = stoi(time.substr(0,2)) * 60;
        minutes += stoi(time.substr(3,5));
        
        set<int> digits;
        
        for (auto it: time) {
            digits.insert(it - '0');
        }
        
        while (true) {
            bool isValid = true;
            minutes = (minutes + 1) % (24 * 60);
            
            int nextTime[] = {minutes / 60 / 10, minutes / 60 % 10, minutes % 60 / 10, minutes % 60 % 10};
            
            for (auto digit: nextTime) {
                if (!digits.contains(digit)) {
                    isValid = false;
                }
            }
            
            if (isValid) {
                char* a = new char[10];
                char* b = new char[4];
                sprintf(a, "%2d", minutes / 60);
                sprintf(b, "%2d", minutes % 60);
                string str_a = a;
                string str_b = b;
                string res = str_a + ":" + str_b;
                
                for (int i=0; i<res.length(); i++) {
                    if (res[i] == ' ') {
                        res[i] = '0';
                    }
                }
                return res;
            }
        }
    }
};
