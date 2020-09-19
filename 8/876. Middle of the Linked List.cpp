class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode *ret = head;
        while(head) {
            ++n;
            head = head->next;
        }
        n >>= 1;
        while(n--)
            ret = ret->next;
        return ret;
    }
};
