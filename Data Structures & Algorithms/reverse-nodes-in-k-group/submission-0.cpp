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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //First let us calculate the total number of reversals
        ListNode* tmp = head; int totalLen = 0;
        while(tmp){
            totalLen++;
            tmp = tmp->next;
        }

        int totalReversals = totalLen/k;
        if(totalReversals == 0) return head;


        ListNode*prev = nullptr;
        ListNode* curr= head;

        ListNode* right = head;
        for(int i = 1; i<k; i++){
            right = right->next;
        }

        //right points to the right most node that we need to reverse in this pass
        for(int i = 1; i<=k; i++){
            ListNode* next = curr->next;
            if(i == 1){
                prev= curr;
                curr = next;
                continue;
            }
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
