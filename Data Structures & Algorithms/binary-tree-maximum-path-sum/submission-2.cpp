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
    int ans;
    int recur(TreeNode*root)
    {
        if(!root)
            return 0;
        int leftSum = recur(root->left);
        int rightSum = recur(root->right);
        ans = max({ans , root->val, root->val+leftSum, root->val+rightSum, root->val+leftSum+rightSum});
        return max({root->val, root->val+leftSum, root->val+rightSum});
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        int res = recur(root);
        // cout<<res<<endl;
        return ans;
    }
};
