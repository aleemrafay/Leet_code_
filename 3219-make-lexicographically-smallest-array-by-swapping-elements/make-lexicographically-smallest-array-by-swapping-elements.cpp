//aleem_rafay
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        unordered_map<int, int> valToGroup;
        vector<queue<int>> groupList;
        
        int groupIdx = 0;
        valToGroup[sortedNums[0]] = groupIdx;
        groupList.push_back(queue<int>());
        groupList[groupIdx].push(sortedNums[0]);
        
        for (int i = 1; i < n; ++i) {
            if (sortedNums[i] - sortedNums[i - 1] > limit) {
                groupIdx++;
                groupList.push_back(queue<int>());
            }
            valToGroup[sortedNums[i]] = groupIdx;
            groupList[groupIdx].push(sortedNums[i]);
        }
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            int g = valToGroup[nums[i]];
            result[i] = groupList[g].front();
            groupList[g].pop();
        }
        
        return result;
    }
};