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
    int helper(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(!root) return 0;
        if(dp[root] != -1) return dp[root];

        int num1 = helper(root->right, dp) + helper(root->left, dp);
        int num2= root->val;
        if(root->left) num2 += helper(root->left->left, dp) + helper(root->left->right, dp);
        if(root->right) num2 += helper(root->right->left, dp) + helper(root->right->right, dp);

        return dp[root] = max(num1, num2); 
    }

    void dfs(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(!root) return;
        dp[root] = -1;
        dfs(root->left, dp);
        dfs(root->right, dp);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        dfs(root, dp);
        return helper(root, dp);
    }
};