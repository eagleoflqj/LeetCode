class Solution {
    static inline void advance(ListNode **&p) {
        p = &(*p)->next;
    }
    static inline void clone(ListNode **&p, ListNode *l) {
        while(l) {
            *p = new ListNode(l->val);
            l = l->next;
            advance(p);
        }
    }
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret, **current = &ret;
        while(l1 && l2) {
            *current = new ListNode;
            if(l1->val < l2->val) {
                (*current)->val = l1->val;
                l1 = l1->next;
            } else {
                (*current)->val = l2->val;
                l2 = l2->next;
            }
            advance(current);
        }
        clone(current, l1);
        clone(current, l2);
        *current = nullptr;
        return ret;
    }
};
