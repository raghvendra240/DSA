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
    int help(TreeNode *root,int val){
        if(!root)
            return 0;
        int right=help(root->right,val);
        int org=root->val;
        root->val+=right+val;
        int left=help(root->left,root->val);
        return left+right+org;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        
        if(root==NULL)
            return NULL;
        int val=0;
        help(root,val);
        return root;
    }
};