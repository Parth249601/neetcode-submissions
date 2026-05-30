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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key == root->val){

            if (!root->left)  { TreeNode* r = root->right; delete root; return r; }
            if (!root->right) { TreeNode* l = root->left;  delete root; return l; }
            
            TreeNode* succ = root->right;
            while (succ->left) succ = succ->left;         // leftmost of right subtree
            root->val = succ->val;                        // copy value into root
            root->right = deleteNode(root->right, succ->val);  // delete the successor
            return root;
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);   // relink!
            return root;
        }
        else {
            root->left = deleteNode(root->left, key);     // relink!
            return root;
        }


    }
};