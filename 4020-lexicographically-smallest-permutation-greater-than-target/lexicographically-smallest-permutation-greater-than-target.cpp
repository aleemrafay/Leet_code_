//aleem_rafay
class Solution {
public:
    std::string lexGreaterPermutation(std::string s, std::string target) {
        int n = s.length();
        std::vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int matched = 0;
        while (matched < n && count[target[matched] - 'a'] > 0) {
            count[target[matched] - 'a']--;
            matched++;
        }

        for (int i = matched; i >= 0; --i) {
            if (i < matched) {
                count[target[i] - 'a']++;
            }

            if (i < n) {
                for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                    if (count[c] > 0) {
                        std::string res = target.substr(0, i);
                        res += (char)('a' + c);
                        count[c]--;

                        for (int r = 0; r < 26; ++r) {
                            while (count[r] > 0) {
                                res += (char)('a' + r);
                                count[r]--;
                            }
                        }
                        return res;
                    }
                }
            }
        }

        return ""; 
    }
};