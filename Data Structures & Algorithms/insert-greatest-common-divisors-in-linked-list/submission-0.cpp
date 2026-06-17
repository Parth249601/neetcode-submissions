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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*tmp = head;
        while(tmp && tmp->next){
            int nextVal = tmp->next->val;
            int currVal = tmp->val;
            int val_node = gcd(currVal, nextVal);
            ListNode* in_between = new ListNode(val_node, tmp->next);
            tmp->next = in_between;
            tmp = tmp->next->next;
        }
        return head;
    }
};