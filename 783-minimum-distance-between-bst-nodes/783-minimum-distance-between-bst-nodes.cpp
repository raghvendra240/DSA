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
    int res=INT_MAX;
    void help(TreeNode *root,int &prev){
        if(!root)
            return;
         help(root->left,prev);
        if(prev!=INT_MAX)
           res=min(res,abs(root->val-prev));
        prev=root->val;
        help(root->right,prev);
        return;
        
    }
public:
    int minDiffInBST(TreeNode* root) {
        int prev=INT_MAX;
        help(root,prev);
        return res;
        
    }
};