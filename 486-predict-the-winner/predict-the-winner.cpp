class Solution {
public:
    int solve(vector<int>& nums, int i, int j)
    {
        if(i == j)
            return nums[i];

        int pickLeft = nums[i] - solve(nums, i+1, j);
        int pickRight = nums[j] - solve(nums, i, j-1);

        return max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums)
    {
        int n = nums.size();
        int diff = solve(nums, 0, n-1);
        return diff >= 0;
    }
};