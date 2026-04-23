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
private:
    bool balanced;
    int calculateHeight(TreeNode*root)
    {
        if(!root)
            return 0;

        int leftHt = calculateHeight(root->left);
        int rightHt = calculateHeight(root->right);

        if(abs(leftHt-rightHt)>1)
            balanced = false;

        return 1+max(leftHt,rightHt);
    }
public:
    bool isBalanced(TreeNode* root) {
        balanced = true;
        calculateHeight(root);
        return balanced;
    }
};
