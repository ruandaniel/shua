2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


Sol1:
O(n)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pre = new ListNode(0), *p = pre;
        int c = 0;
        while (l1 != NULL || l2 != NULL){
            int sum = c;
            if (l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            c = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
        }
        if (c) p->next = new ListNode(c);
        return pre->next;
    }
};