class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **p = &head;
        while(*p) {
            if((*p)->val == val) {
                ListNode *temp = *p;
                *p = (*p)->next;
                delete temp;
            } else
                p = &(*p)->next;
        }
        return head;
    }
};
