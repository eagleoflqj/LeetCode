class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ret = 0;
        while(head) {
            ret = (ret << 1) | head->val;
            head = head->next;
        }
        return ret;
    }
};
