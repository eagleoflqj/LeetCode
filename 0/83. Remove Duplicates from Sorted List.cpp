class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *node = head, *next;
        while(node && (next = node->next))
            if(node->val == next->val) {
                node->next = next->next;
                delete next;
            } else
                node = next;
        return head;
    }
};
