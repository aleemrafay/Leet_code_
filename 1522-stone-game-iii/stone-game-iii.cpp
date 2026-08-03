//aleem_rafay_
class Solution {
private:
    int solve(vector<int>& stoneValue, int i, vector<int>& dp) {
        int n = stoneValue.size();

        if (i >= n) return 0;

        if (dp[i] != INT_MIN) return dp[i];

        int max_lead = INT_MIN; 
        int current_sum = 0;

        for (int choices = 1; choices <= 3; choices++) {
            if (i + choices - 1 < n) {
                current_sum += stoneValue[i + choices - 1];
                int lead = current_sum - solve(stoneValue, i + choices, dp);
                max_lead = max(max_lead, lead);
            }
        }

        return dp[i] = max_lead;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        vector<int> dp(n, INT_MIN);

        int alice_lead = solve(stoneValue, 0, dp);
        if (alice_lead > 0) {
            return "Alice";
        } else if (alice_lead < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};