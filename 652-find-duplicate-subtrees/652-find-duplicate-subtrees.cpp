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
     vector<TreeNode*>res;
     unordered_map<string,int>dp;
     string dfs(TreeNode*root){
        if(root==NULL){
            return "NULL|";
        }

        string left=dfs(root->left);
        string right=dfs(root->right);
        string temp= to_string(root->val)+"|"+left+right;
        if(dp[temp]==1)
            res.push_back(root);
        dp[temp]++;
        return temp;
     }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};