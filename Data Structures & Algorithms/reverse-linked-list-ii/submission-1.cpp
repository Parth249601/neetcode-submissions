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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        
        ListNode dummy(0); dummy.next= head;
        ListNode* curr = dummy.next; ListNode* left_node = dummy.next;
        ListNode* prev = &dummy;
        for(int i = 1; i<left; i++){
            left_node = left_node->next;
            curr = curr->next;
            prev = prev->next;
        }
        
        ListNode* right_node = dummy.next;
        for(int i=1; i< right; i++)
            right_node = right_node->next;
        
        //prev is the pointer just before the left, curr is the left
        //left and right are pointers to the left and the right node 
        prev -> next = right_node;
        for(int i = 1; i <= (right-left+1); i++){
            ListNode* next = curr->next;
            if(i != 1) curr->next = prev;
            prev = curr;
            curr = next;
        }
        left_node->next= curr;

        return dummy.next;

    }
};