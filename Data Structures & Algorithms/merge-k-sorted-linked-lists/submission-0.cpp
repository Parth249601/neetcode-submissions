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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        using minHeap = priority_queue<int, vector<int>, greater<int>>;
        vector<minHeap> bigHeap;
        int totalLen = 0;
        for(ListNode* head : lists){
            minHeap pq;
            while(head){
                pq.push(head->val);
                head = head->next;
                totalLen++;
            }
           
            bigHeap.push_back(pq);
        }

        if(totalLen == 0){
            return NULL;
        }
        ListNode* mainHead = new ListNode();
        ListNode* tmp = mainHead;
        for(int i = 0; i< totalLen; i++){
            //Iterate through bigHeap
            int minVal = INT_MAX, minIndex;
            for(int j =0; j<bigHeap.size(); j++){
                if(!bigHeap[j].empty() && bigHeap[j].top() < minVal){
                    minVal = bigHeap[j].top();
                    minIndex = j;
                }
            }
            int val = bigHeap[minIndex].top();
            tmp->val = val;
            bigHeap[minIndex].pop();
            if(i != totalLen -1) tmp->next= new ListNode();
            tmp = tmp->next;
        }
        return mainHead;
    }
};
