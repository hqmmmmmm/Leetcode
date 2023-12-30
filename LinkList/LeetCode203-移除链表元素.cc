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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1, head);

        auto it = dummy;
        while(it->next)
        {
            auto tmp = it->next;
            if(tmp->val == val)
                it->next = tmp->next;
            else
                it = tmp;
        }
        
        return dummy->next;
    }
};