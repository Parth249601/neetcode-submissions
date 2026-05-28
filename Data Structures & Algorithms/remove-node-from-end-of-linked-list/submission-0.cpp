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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0); dummy.next = head;
        ListNode* slow = &dummy; ListNode* fast = & dummy;
        for(int i=0; i<=n; i++) fast = fast->next; //fast is n+1 points ahead slow
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        //fast ->NULL be last element, slow->next will exactly be nth Node point
        ListNode* victim = slow->next;
        slow->next = victim->next; 
        delete victim;
        return dummy.next;

    }
};
