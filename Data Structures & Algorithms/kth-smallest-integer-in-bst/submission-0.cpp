/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    using maxHeap = priority_queue<int>;
public:
    void dfs(TreeNode* root, maxHeap& pq, int k){
        if(!root) return;
        if(pq.size() >= k) {
            if(root->val < pq.top()){
                pq.pop();
                pq.push(root->val);
            }
        }
        else pq.push(root->val);
        dfs(root->left, pq, k);
        dfs(root->right, pq, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        maxHeap pq;
        dfs(root, pq, k);
        return pq.top();
    }
};
