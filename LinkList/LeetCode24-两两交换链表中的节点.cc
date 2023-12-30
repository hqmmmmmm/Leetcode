/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(-1, head);
        auto pre = dummy, p = pre->next;
        
        while(p && p->next)
        {
            auto q = p->next;
            pre->next = q;
            p->next = q->next;
            q->next = p;
            
            pre = p;
            p = pre->next;
        }
        return dummy->next;
    }
};