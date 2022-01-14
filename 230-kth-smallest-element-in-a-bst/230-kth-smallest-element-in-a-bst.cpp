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
    void help(TreeNode *root,int &k,int &res,int &index){
        if(!root)
            return;
        help(root->left,k,res,index);
        index++;
        if(k==index)
        {
            res=root->val;
            return;
        }
        help(root->right,k,res,index);
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
       int res;
        int index=0;
       help(root,k,res,index);
       return res;
        
        
    }
};