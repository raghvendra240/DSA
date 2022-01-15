class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            return new TreeNode(val,root,NULL);
        }
        queue<TreeNode*>q;
        --depth;
        q.push(root);
        while(q.size()>0){
            int n=q.size();
            --depth;
            while(n--){
                auto curr=q.front();
                q.pop();
                if(depth==0){
                    TreeNode *left=curr->left,*right=curr->right;
                    curr->left=new TreeNode(val,left,NULL);
                    curr->right=new TreeNode(val,NULL,right);
                }else{
                   
                   if(curr->left){
                    q.push(curr->left);
                   }
                   if(curr->right){
                      q.push(curr->right);
                   }   
                }
            }
            if(depth==0)
                break;
        }
        return root;
    }
};