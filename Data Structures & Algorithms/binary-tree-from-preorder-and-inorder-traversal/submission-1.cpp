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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if(size == 0) return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
           

        vector<int> left_inorder, right_inorder;
        bool a = true;

        for(int i=0; i < size; i++){
            if(inorder[i] != preorder[0] && a) left_inorder.push_back(inorder[i]);
            if(inorder[i] == preorder[0]) a = false;
            if(inorder[i] != preorder[0] && !a) right_inorder.push_back(inorder[i]);
        }
        int ls = left_inorder.size();
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + ls + 1);
        vector<int> right_preorder(preorder.begin() + ls + 1, preorder.end());

        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);

        return root;
    }
};
