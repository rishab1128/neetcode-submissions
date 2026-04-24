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
    bool isValidBST(TreeNode* root, int mini=INT_MIN, int maxi=INT_MAX) {

       if(!root)
            return true;

        if(root->val >= maxi)
            return false;

        if(root->val <= mini)
            return false;

        bool leftAns = isValidBST(root->left , mini, root->val);
        bool rightAns = isValidBST(root->right, root->val, maxi);

        return leftAns && rightAns;
        
    }
};
