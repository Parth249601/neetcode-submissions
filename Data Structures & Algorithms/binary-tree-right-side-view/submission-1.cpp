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
public:
    void helper(TreeNode* root, vector<int>& ans){
        //right most node visible at each depth
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            int size = qt.size();
            while(size--){
                TreeNode* curr = qt.front(); qt.pop();
                if(size == 0) ans.push_back(curr->val);
                if(curr->left) qt.push(curr->left);
                if(curr->right) qt.push(curr->right);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        helper(root, ans);
        return ans;
    }
};
