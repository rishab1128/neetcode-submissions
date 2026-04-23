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
    vector<int> rightSideView(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(q.size())
        {
            int sz = q.size();
            vector<int>lvl;
            for(int i=0; i<sz; i++)
            {
                TreeNode*node = q.front();
                q.pop();
                if(node)
                {
                    lvl.push_back(node->val);
                    q.push(node->right);
                    q.push(node->left);
                }
            }
            if(lvl.size()>0)
                ans.push_back(lvl[0]);
        }
        return ans;
        
    }
};
