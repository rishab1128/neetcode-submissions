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
    map<int,vector<int>>mp;
    void dfs(TreeNode*node, int level)
    {
        if(!node)
            return;
        mp[level].push_back(node->val);
        dfs(node->left,level+1);
        dfs(node->right,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        mp.clear();
        dfs(root,0);
        vector<vector<int>>ans;
        for(auto&[lev,vec]:mp){
            ans.push_back(vec);
        }
        return ans;
    }
};
