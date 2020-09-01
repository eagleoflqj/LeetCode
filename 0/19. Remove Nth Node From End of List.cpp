class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode**> q;
        ListNode **current = &head;
        while(*current) {
            if(q.size() == n)
                q.pop();
            q.push(current);
            current = &(*current)->next;
        }
        ListNode *next = *q.front();
        *q.front() = next->next;
        delete next;
        return head;
    }
};
