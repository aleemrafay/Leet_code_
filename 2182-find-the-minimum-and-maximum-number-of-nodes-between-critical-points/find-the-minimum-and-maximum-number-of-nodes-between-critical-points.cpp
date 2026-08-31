//aleem_rafay
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int firstCritical = -1;
        int lastCritical = -1;
        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1; 
        while (curr->next != nullptr) {
            bool isLocalMin = (curr->val < prev->val) && (curr->val < curr->next->val);
            bool isLocalMax = (curr->val > prev->val) && (curr->val > curr->next->val);

            if (isLocalMin || isLocalMax) {
                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    minDistance = min(minDistance, index - lastCritical);
                }
                lastCritical = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        int maxDistance = lastCritical - firstCritical;
        return {minDistance, maxDistance};
    }
};