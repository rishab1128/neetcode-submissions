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
    int cnt;
    void dfs(TreeNode*node, int currMax)
    {
        if(!node)
            return;
        if(node->val >= currMax){
            cnt++;
            currMax = node->val;
        }
        dfs(node->left, currMax);
        dfs(node->right, currMax);
    }
    int goodNodes(TreeNode* root) {

        cnt = 0;
        int maxi = INT_MIN;
        dfs(root,maxi);
        return cnt;
    }
};
