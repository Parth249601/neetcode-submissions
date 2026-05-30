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
    int Max(TreeNode* root){
        if(!root) return INT_MIN;
        int num1 = Max(root->left);
        int num2 = Max(root->right);
        return max(root->val, max(num1, num2));
    }
    int Min(TreeNode* root){
        if(!root) return INT_MAX;
        int num1 = Min(root->left);
        int num2 = Min(root->right);
        return min(root->val, min(num1, num2));
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        bool a = true, b = true;
        if(root->left) a = root->left->val < root->val;
        if(root->right) b = root->right->val > root->val;
        
        int MinRight = Min(root->right); int MaxLeft = Max(root->left);
        cout << "Min Right value " << MinRight << endl;
        cout << "Max Left value " << MaxLeft << endl;

        return (a && b && isValidBST(root->right) && isValidBST(root->left) && (MinRight > root->val) && (MaxLeft < root->val));

    }
};
