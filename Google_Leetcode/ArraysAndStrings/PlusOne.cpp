class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int car = 0, num;
        int n = digits.size();
        for (int i=n-1; i>=0; i--) {
            num = digits[i] + car;
            if (i == n-1) {
                num += 1;
            }
            car = num / 10;
            num %= 10;
            digits[i] = num;
        }
        cout<< car;
        if (car > 0) {
            if (car/10 == 0) {
                digits.insert(digits.begin(), car);
                cout<< car;
            }
            else {
                while (car%10 == 0) {
                    digits.insert(digits.begin(), car/10);
                    car %= 10;
                }
            }
        }

        return digits;
    }
};
