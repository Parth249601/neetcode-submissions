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
    bool isSame(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if((!p && q) || (p && !q)) return false;
        return (p->val == q->val && isSame(p->left, q->left) && isSame(p->right, q->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top(); st.pop();
            if(isSame(curr, subRoot)) return true;
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
        }
        return false;
    }
};
