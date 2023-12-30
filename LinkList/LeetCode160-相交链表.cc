/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto pA = headA, pB = headB;
        while(pA != pB)
        {
            // 先判断pA和pB是否为空，如果移到后面，会干扰while循环的退出条件
            pA = pA ? pA : headB;
            pB = pB ? pB : headA;

            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};