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
        int depth1 = 1 + depth(root->left);
        int depth2 = 1 + depth(root->right);
        return max(depth1, depth2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return max(depth(root) - 1, diameterOfBinaryTree(root->right));
        if(!root->right) return max(depth(root) - 1, diameterOfBinaryTree(root->left));


        //gotta calculate 3 figures
        int num1 = diameterOfBinaryTree(root->left);
        int num2 = diameterOfBinaryTree(root->right);

        int depth_from_left_subTree = depth(root->left) + 1;
        int depth_from_right_subTree = depth(root->right) + 1;

        int num3 = depth_from_left_subTree + depth_from_right_subTree - 2;
        return max(num1, max(num2, num3));

    }
};
