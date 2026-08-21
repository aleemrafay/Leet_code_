//aleem_rafay
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        auto gcd = [](long long a, long long b) {
            return std::gcd(a, b);
        };
        
        auto lcm = [&](long long a, long long b) {
            return (a / gcd(a, b)) * b;
        };

        long long low = 1;
        long long high = (long long)*min_element(coins.begin(), coins.end()) * k;
        long long ans = high;

        auto countMultiples = [&](long long x) {
            long long total = 0;
            
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long current_lcm = 1;
                int bits_count = 0;
                bool overflow = false;

                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        bits_count++;
                        current_lcm = lcm(current_lcm, coins[i]);
                        if (current_lcm > x) { 
                            overflow = true;
                            break;
                        }
                    }
                }

                if (overflow) continue;

                if (bits_count % 2 == 1) {
                    total += x / current_lcm;
                } else {
                    total -= x / current_lcm;
                }
            }
            return total;
        };

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (countMultiples(mid) >= k) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;  
            }
        }

        return ans;
    }
};