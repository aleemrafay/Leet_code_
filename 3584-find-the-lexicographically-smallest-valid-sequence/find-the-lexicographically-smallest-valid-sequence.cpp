//aleem_rafay
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        vector<int> last_match(m, -1);
        
        int j = n - 1;
        for (int i = m - 1; i >= 0; --i) {
            while (j >= 0 && word1[j] != word2[i]) {
                j--;
            }
            last_match[i] = j;
            j--;
        }
        
        vector<int> ans;
        bool changed = false;
        j = 0;
        
        for (int i = 0; i < m; ++i) {
            while (j < n) {
                bool is_match = (word1[j] == word2[i]);
                bool can_finish_exact = (i == m - 1) || (last_match[i + 1] > j);
                
                if (is_match) {
                    if (!changed || can_finish_exact) {
                        ans.push_back(j);
                        j++;
                        break;
                    }
                } else {
                    if (!changed && can_finish_exact) {
                        changed = true;
                        ans.push_back(j);
                        j++;
                        break;
                    }
                }
                j++;
            }
        }
        
        return (ans.size() == m) ? ans : vector<int>();
    }
};