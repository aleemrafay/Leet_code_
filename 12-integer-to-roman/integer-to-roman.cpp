class Solution {
public:
//aleem_rafay_
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string s = "";
        int i = 0;
        while (num > 0) {
            if (num >= values[i]) {
                s += symbols[i];
                num -= values[i];
            } else {
                i++;
            }
        }
        return s;
    }
};