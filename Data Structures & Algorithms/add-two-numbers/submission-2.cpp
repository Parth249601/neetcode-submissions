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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp1 = l1; ListNode* tmp2 = l2; ListNode ans = ListNode(0);
        ListNode* tmp = &ans;
        if(!l1) return l2; if(!l2) return l1;
        int carry = 0; int val1 = 0, val2 = 0;
        while(tmp1 || tmp2 || carry){
            val1 = tmp1 ? tmp1->val : 0;
            val2 = tmp2 ? tmp2->val : 0;
            int num = val1 + val2;
            int total = num + carry;

            carry = total / 10;

            if(total >= 10) total = total%10;

            tmp->next = new ListNode(total); 
            tmp = tmp->next; 

            if(tmp1 && tmp1->next) tmp1 = tmp1 ->next;
            else tmp1 = NULL;

            if(tmp2 && tmp2->next) tmp2 = tmp2->next;
            else tmp2 = NULL;
        }
        return ans.next;
    }
};
