/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 为什么fast走两步，fast走三步可不可以？
class Solution {  
public:
    ListNode *detectCycle(ListNode *head) {  // 这题不需要用dummy头结点
        if(!head || !head->next) return nullptr;

        auto slow = head->next, fast = slow->next;
        while(fast != slow)
        {
            if(fast == nullptr || fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        }

        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};