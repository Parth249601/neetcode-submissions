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
    int depth(TreeNode* root){
        if(!root) return 0;
        int depth1= 1 + depth(root->left);
        int depth2 = 1+ depth(root->right);

        return max(depth1, depth2);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int h1 = depth(root->left);
        int h2 = depth(root->right);
        bool first = abs(h1-h2) <= 1;

        return (first && isBalanced(root->left) && isBalanced(root->right));
    }
};
