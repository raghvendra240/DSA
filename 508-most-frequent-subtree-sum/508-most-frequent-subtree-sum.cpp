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
    int higestFrequency=0;
    unordered_map<int,int>dp;
    int help(TreeNode* root){
        if(!root)
            return 0;
        
        int sum=root->val  + help(root->left) + help(root->right);
        dp[sum]++;
        higestFrequency=max(higestFrequency,dp[sum]);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dp.clear();
        help(root);
        vector<int>res;
        for(auto temp : dp){
            if(temp.second==higestFrequency)
                res.push_back(temp.first);
        }
        return res;
    }
};