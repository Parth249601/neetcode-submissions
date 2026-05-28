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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        //we can do it recursively 
        //Step 1. Get a pointer to the second Last Node.
        ListNode* tmp = head;
        while(tmp->next->next)
            tmp = tmp->next;
        //Step 2. Insert n-1 in between the first two nodes
        ListNode* victim = tmp->next; //Last Node 
        victim->next = head->next; 
        head->next = victim;
        tmp->next = NULL;
        reorderList(head->next->next);
    }
};
