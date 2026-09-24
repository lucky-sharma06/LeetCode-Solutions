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
    bool checkTree(TreeNode* root) {
        if(root == nullptr) return true;
        // handle the leaf node 
        if(root -> left == nullptr && root -> right == nullptr) return true;

        int l = 0, r = 0;
        if(root -> left != nullptr) l = root -> left -> val;
        if(root -> right != nullptr) r = root -> right -> val;
        return ((root -> val == l + r) && checkTree(root -> left) && checkTree(root -> right));
    }
};