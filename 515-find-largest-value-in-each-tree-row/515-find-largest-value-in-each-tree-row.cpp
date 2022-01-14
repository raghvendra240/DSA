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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        int temp;
        while(q.empty()==false){
             int n=q.size();
             temp=INT_MIN;
             for(int i=0;i<n;i++){
                auto curr=q.front();q.pop();
                temp=max(temp,curr->val);

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
             }
             res.push_back(temp);
        }
        return res;
    }
};