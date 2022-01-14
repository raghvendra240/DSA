```
//My solution
class Solution {
vector<int>dp;
public:
int pathSum(TreeNode* root, int targetSum) {
if(root==NULL)
return 0;
int index=dp.size()-1;
int sum=root->val;
int res=0;
while(index>=0){
if(sum==targetSum)
res++;
sum+=dp[index];
index--;
}
if(sum==targetSum)
res++;
dp.push_back(root->val);
int left=pathSum(root->left,targetSum);
int right=pathSum(root->right,targetSum);
dp.pop_back();
return left+right+res;
}
};
```