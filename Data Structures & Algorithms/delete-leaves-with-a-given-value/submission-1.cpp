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
    bool delete_node(TreeNode*& root, int target){
        if(!root) return false;
        if(root->val == target && !root->left && !root->right){
            root = NULL;
            return true;
        }

        if(root->val != target && !root->left && !root->right) return false;

        bool a = delete_node(root->left, target);
        bool b = delete_node(root->right, target);
        return a || b;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;

        // 1. Explore and update the left and right children FIRST (Post-order)
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // 2. Check the current node on the way back up.
        if (!root->left && !root->right && root->val == target) {
            delete root;     
            return nullptr;  
        }

        return root;
    }
};