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
    int sum=0;
    void help(TreeNode *root){
        if(!root)
            return;
        help(root->right);
        sum+=root->val;
        root->val=sum;
        help(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        
        if(root==NULL)
            return NULL;
        sum=0;
        help(root);
        return root;
    }
};