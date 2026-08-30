//aleem_rafay
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int minIdx = 0, maxIdx = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);

        int option1 = j + 1;

        int option2 = n - i;

        int option3 = (i + 1) + (n - j);

        return min({option1, option2, option3});
    }
};