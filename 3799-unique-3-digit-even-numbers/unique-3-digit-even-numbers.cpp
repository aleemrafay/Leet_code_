//aleem_rafay
class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        std::vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }

        int total_unique = 0;
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;      
            int d2 = (num / 10) % 10;
            int d3 = num % 10;       

            std::vector<int> req(10, 0);
            req[d1]++;
            req[d2]++;
            req[d3]++;

            bool valid = true;
            for (int d = 0; d <= 9; ++d) {
                if (req[d] > count[d]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                total_unique++;
            }
        }

        return total_unique;
    }
};