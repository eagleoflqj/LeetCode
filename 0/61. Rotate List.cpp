class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return nullptr;
        vector<ListNode*> v;
        do {
            v.push_back(head);
        } while((head = head->next));
        int n = v.size(), h = (n - k % n) % n, t = (h + n - 1) % n;
        v.back()->next = v[0];
        v[t]->next = nullptr;
        return v[h];
    }
};
