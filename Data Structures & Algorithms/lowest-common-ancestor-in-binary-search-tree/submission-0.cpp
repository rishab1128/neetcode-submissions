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
    vector<TreeNode*>findPath(TreeNode*root, TreeNode*node)
    {
        vector<TreeNode*>ans;
        while(root && node)
        {
            ans.push_back(root);
            if(root->val > node->val)
                root = root->left;
            else if(root->val < node->val)
                root = root->right;
            else
                break;
        }
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*>path1 = findPath(root,p);
        vector<TreeNode*>path2 = findPath(root,q);

        int n1 = path1.size() , n2 = path2.size();
        TreeNode*ans = NULL;

        for(int i=0; i<min(n1,n2); i++){
            if(path1[i]->val==path2[i]->val)
                ans = path1[i];
            else
                break;
        }
        return ans;
        
    }
};
