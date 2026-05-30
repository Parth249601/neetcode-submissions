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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            int size = qt.size();
            vector<int> level;
            while(size--){
                TreeNode* front = qt.front();
                level.push_back(front->val);
                qt.pop();
                if(front->left) qt.push(front->left);
                if(front->right) qt.push(front->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
