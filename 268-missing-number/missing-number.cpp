//aleem_rafay_
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = 0;
        int actualSum = 0;

        for (int i = 0; i < n; i++) {
            expectedSum += i;
            actualSum += nums[i];
        }
        expectedSum += n;

        return expectedSum - actualSum;
    }
};