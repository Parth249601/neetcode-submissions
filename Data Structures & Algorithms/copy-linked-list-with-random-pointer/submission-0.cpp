/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* tmp = head;
        unordered_map<Node*, Node*> mp;

        while(tmp){
            mp[tmp] = new Node(tmp->val);
            tmp = tmp->next;
        }

        tmp = head;
        while(tmp){
            if(tmp->next) mp[tmp]->next = mp[tmp->next];
            if(tmp->random) mp[tmp]->random = mp[tmp->random];
            tmp = tmp->next;
        }
        return mp[head]; 
    }
};
