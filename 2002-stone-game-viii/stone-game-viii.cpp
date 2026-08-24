//aleem_rafay
class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        int maxDiff = stones[n - 1];
        for (int i = n - 2; i >= 1; --i) {
            maxDiff = std::max(maxDiff, stones[i] - maxDiff);
        }
        
        return maxDiff;
    }
};