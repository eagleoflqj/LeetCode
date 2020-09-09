class Solution {
    static bool compare(const ListNode *a, const ListNode *b) {
        if(!(a && b))
            return a;
        return a->val > b->val;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype(&compare)> q(compare);
        for(auto node : lists)
            q.push(node);
        ListNode *head = nullptr, **tail = &head;
        while(!q.empty()) {
            ListNode *t = q.top();
            q.pop();
            if(!t)
                continue;
            ListNode *next = t->next;
            *tail = t;
            tail = &t->next;
            if(next)
                q.push(next);
        }
        return head;
    }
};
