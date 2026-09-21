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
    int findSum(TreeNode* root, int& maxi){
        if(root == nullptr) return 0;

        int leftSum = max(0, findSum(root -> left, maxi));
        int rightSum = max(0, findSum(root -> right, maxi));

        // if(leftSum < 0) leftSum = 0;
        // if(rightSum < 0) rightSum = 0; or 

        maxi = max(maxi, root -> val + leftSum + rightSum);

        return root -> val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findSum(root, maxi);
        return maxi;
    }
};