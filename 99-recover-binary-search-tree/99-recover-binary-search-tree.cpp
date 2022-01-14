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
    void help(TreeNode *root,TreeNode *&first,TreeNode *&second,TreeNode *&prev){
        if(!root)
            return;
        help(root->left,first,second,prev);
        if(prev && prev->val>root->val){
            if(first==NULL)
                first=prev;
            second=root;
        }
        prev=root;
        help(root->right,first,second,prev);
    }
public:
    void recoverTree(TreeNode* root) {
        
        
        TreeNode *first=NULL,*second=NULL,*prev=NULL;
        help(root,first,second,prev);
        swap(first->val,second->val);
        return;
        
    }
};