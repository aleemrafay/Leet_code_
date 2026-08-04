class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        // bubble sort (aap ka style)
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }

        int minVal = nums[0];
        int maxVal = nums[n-1];

        vector<int> missing;
        int idx = 0;
        for(int l=minVal;l<=maxVal;l++)
        {
            if(idx<n && nums[idx]==l)
            {
                idx++;
            }
            else
            {
                missing.push_back(l);
            }
        }

        return missing;
    }
};