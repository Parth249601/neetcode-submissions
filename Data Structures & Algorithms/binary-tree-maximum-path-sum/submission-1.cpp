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
    int maxSum(TreeNode* root){
        if(!root) return 0;
        int left = maxSum(root->left), right = maxSum(root->right);
        int max_child = max(left, right);
        return root->val + max(0, max_child);
    }
    int maxPathSum(TreeNode* root) {
        int global_max = INT_MIN;
        queue<TreeNode*> qt;
        if(!root) return 0;
        qt.push(root);
        while(!qt.empty()){
            TreeNode* top = qt.front(); qt.pop();
            int currPeak = top->val;
            int leftPath = maxSum(top->left), rightPath = maxSum(top->right);
            if(leftPath > 0) currPeak += leftPath;
            if(rightPath > 0) currPeak += rightPath;
            global_max = max(global_max, currPeak);
            if(top->left) qt.push(top->left);
            if(top->right) qt.push(top->right);
        }
        return global_max;
    }
};
