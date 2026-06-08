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
    int maxSum(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(!root) return 0;
        if(dp.find(root) != dp.end()) return dp[root];
        int left = maxSum(root->left, dp), right = maxSum(root->right, dp);
        int max_child = max(left, right);
        return dp[root] = root->val + max(0, max_child);
    }
    int maxPathSum(TreeNode* root) {
        int global_max = INT_MIN;
        queue<TreeNode*> qt; unordered_map<TreeNode*, int> dp;
        if(!root) return 0;
        qt.push(root);
        while(!qt.empty()){
            TreeNode* top = qt.front(); qt.pop();
            int currPeak = top->val;
            int leftPath = maxSum(top->left, dp), rightPath = maxSum(top->right, dp);
            if(leftPath > 0) currPeak += leftPath;
            if(rightPath > 0) currPeak += rightPath;
            global_max = max(global_max, currPeak);
            if(top->left) qt.push(top->left);
            if(top->right) qt.push(top->right);
        }
        return global_max;
    }
};
