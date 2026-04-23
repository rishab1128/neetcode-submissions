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
    bool subtree;
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if((p && !q) || (!p && q))
            return false;

        if(!p&&!q)
            return true;

        if(p->val!=q->val)
            return false;

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
    // void dfs(TreeNode* root, TreeNode* subRoot){
    //     if(!root)
    //         return;
    //     if(isSameTree(root,subRoot))
    //         subtree = true;
    //     dfs(root->left,subRoot);
    //     dfs(root->right,subRoot);
    // }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // subtree = false;
        // dfs(root,subRoot);
        // return subtree;
        if(isSameTree(root,subRoot))
           return true;
        if(root)
        {
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        }
        return false;
    }
};
