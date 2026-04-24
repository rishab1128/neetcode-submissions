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
    TreeNode*recur(vector<int>& preorder, int& idx, int start, int end, map<int,int>&pos)
    {
        if(start > end || idx==(int)preorder.size())
        {
            return NULL;
        }
        TreeNode*node = new TreeNode(preorder[idx]);
        int mid = pos[preorder[idx++]];
        node->left = recur(preorder, idx, start,mid-1,pos);
        node->right = recur(preorder,idx,mid+1,end,pos);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        map<int,int>pos;
        for(int i=0; i<(int)inorder.size(); i++)
        {
            pos[inorder[i]] = i;
        }
        int m = inorder.size();
        int idx = 0;
        return recur(preorder,idx,0,m-1,pos);
    }
};
