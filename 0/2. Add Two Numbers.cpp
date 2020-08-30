class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret, **current = &ret;
        int carrage = 0;
        do {
            int d = carrage;
            if(l1) {
                d += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                d += l2->val;
                l2 = l2->next;
            }
            if(d > 9) {
                d -= 10;
                carrage = 1;
            } else
                carrage = 0;
            *current = new ListNode(d);
            current = &(*current)->next;
        } while(l1 || l2 || carrage);
        return ret;
    }
};
