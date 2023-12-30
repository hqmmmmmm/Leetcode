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
    ListNode* reverseList(ListNode* head) {
        // 1、迭代法（双指针法）
        // ListNode *pre = nullptr, *cur = head;
        // while(cur)
        // {
        //     auto tmp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = tmp;
        // }
        // return pre;


        // 2、递归法
        if(!head || !head->next)  // 递归终止条件
            return head;

        auto newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;      // 主要是为了处理头结点的next

        return newHead;
    }
};