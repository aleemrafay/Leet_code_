//aleem_rafay
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        int odd_cnt = 0;
        int odd_char = -1;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 != 0) {
                odd_cnt++;
                odd_char = i;
            }
        }

        if (odd_cnt > 1) return "";

        int half_len = n / 2;
        vector<int> half_cnt(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_cnt[i] = cnt[i] / 2;
        }

        string result = "";
        
        auto check = [&](auto& self, int idx, bool is_greater) -> bool {
            if (idx == half_len) {
                string full = result;
                if (n % 2 != 0) {
                    full += (char)('a' + odd_char);
                }
                string right = result;
                reverse(right.begin(), right.end());
                full += right;

                if (full > target) {
                    result = full;
                    return true;
                }
                return false;
            }

            char target_char = target[idx];
            int start_c = is_greater ? 0 : (target_char - 'a');

            for (int c = start_c; c < 26; ++c) {
                if (half_cnt[c] > 0) {
                    half_cnt[c]--;
                    result.push_back((char)('a' + c));

                    bool next_is_greater = is_greater || (c > (target_char - 'a'));
                    if (self(self, idx + 1, next_is_greater)) {
                        return true;
                    }

                    result.pop_back();
                    half_cnt[c]++;
                }
            }
            return false;
        };

        if (check(check, 0, false)) {
            return result;
        }

        return "";
    }
};