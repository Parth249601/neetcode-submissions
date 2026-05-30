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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //do a inorder traversal
        string s;
        if(!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    TreeNode* rec(stringstream& ss){
        string tok; getline(ss, tok, ',');
        if (tok == "#") return nullptr;   // null marker -> stop
        auto* n = new TreeNode(stoi(tok));
        n->left  = rec(ss);               // build left, then right
        n->right = rec(ss);
        return n;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return rec(ss);

    }
};
