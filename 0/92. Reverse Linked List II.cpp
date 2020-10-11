class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode **b = &head, *prev, *current, *next;
        n -= m;
        while(--m)
            b = &(*b)->next;
        for(prev = *b, next = current = prev->next; n--; prev = current, current = next) {
            next = current->next;
            current->next = prev;
        }
        (*b)->next = next;
        *b = prev;
        return head;
    }
};
