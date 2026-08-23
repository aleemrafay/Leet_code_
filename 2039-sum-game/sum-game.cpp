//aleem_rafay
class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.size();
        int left_sum = 0, right_sum = 0;
        int left_q = 0, right_q = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                left_q++;
            } else {
                left_sum += num[i] - '0';
            }
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                right_q++;
            } else {
                right_sum += num[i] - '0';
            }
        }

        int sum_diff = left_sum - right_sum;
        int q_diff = left_q - right_q;

        if (q_diff % 2 != 0) {
            return true;
        }

         return sum_diff + (q_diff / 2) * 9 != 0;
    }
};