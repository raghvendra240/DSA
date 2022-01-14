/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    string res;
    void help(TreeNode *root){
        if(root==NULL){
            res+="|NULL";
            return;
        }
        res+="|"+to_string(root->val);
        help(root->left);
        help(root->right);
    }
    
    TreeNode *help2(vector<string>&data,int &index){
        if(index>=data.size())
            return NULL;
        
        TreeNode *temp=NULL;
        if(data[index]!="NULL"){
            
            temp=new TreeNode(stoi(data[index]));
        }
        
        if(temp==NULL)
            return temp;
        index++;
        temp->left=help2(data,index);
        index++;
        temp->right=help2(data,index);
          return temp;
        
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        res="";
        if(root==NULL)
            return "";
        help(root);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()<2)
            return NULL;
        int index=1;
        vector<string>nums;
        string temp="";
        for(;index<data.size();index++){
            char c=data[index];
            if(c=='|'){
                nums.push_back(temp);
                temp="";
                continue;
            }
            
            temp+=c;
        }
        
        if(temp.size()){
            nums.push_back(temp);
        }
        
         index=0;
        return help2(nums,index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));