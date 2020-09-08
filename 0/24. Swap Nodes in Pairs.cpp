class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **current = &head, *first, *second;
        while((first = *current) && (second = first->next)) {
            *current = second;
            first->next = second->next;
            second->next = first;
            current = &first->next;
        }
        return head;
    }
};
