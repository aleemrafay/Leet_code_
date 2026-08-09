//aleem_rafay_
class Solution {
private:
    vector<vector<int>> memo;
    vector<int> suffixSum;
    int n;

    int solve(int i, int M) {
        // Base case: If we can grab all remaining piles, take them all
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }
        
        // Return precalculated state
        if (memo[i][M] != 0) {
            return memo[i][M];
        }

        int maxStones = 0;
        
        // Try taking X piles where 1 <= X <= 2M
        for (int X = 1; X <= 2 * M; ++X) {
            int opponentScore = solve(i + X, max(M, X));
            int currentScore = suffixSum[i] - opponentScore;
            maxStones = max(maxStones, currentScore);
        }

        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memo.assign(n, vector<int>(n + 1, 0));
        suffixSum.assign(n + 1, 0);

        // Precompute suffix sums
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        return solve(0, 1);
    }
};