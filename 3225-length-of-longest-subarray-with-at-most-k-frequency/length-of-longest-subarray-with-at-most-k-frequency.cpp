//aleem_rafay
class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Include nums[right] in the window
            freq[nums[right]]++;

            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};