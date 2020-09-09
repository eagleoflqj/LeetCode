class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        ListNode *current = head;
        int n = 1;
        while((current = current->next))
            ++n;
        n /= k;
        ListNode **p = &head, *next, *h;
        current = head;
        while(h = current, next = current->next, n--) {
            for(int i = 1; i < k; ++i) {
                ListNode *temp = next->next;
                next->next = current;
                current = next;
                next = temp;
            }
            *p = current;
            p = &h->next;
            current = next;
            if(!current)
                break;
        }
        *p = current;
        return head;
    }
};
