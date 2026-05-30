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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        //left->root->right;
        stack<TreeNode*> st;
        if(!root) return out;

        TreeNode* curr = root;
        while(curr || !st.empty()){
            while(curr) {st.push(curr); curr = curr->left;} // dive left;
            curr = st.top(); st.pop();
            out.push_back(curr->val); // visit the current
            curr = curr->right;//we need to go right
        }
        return out;
    }
};