class Solution {
    unordered_set<int>used;
    int res=0;
    void dfs(int val,int index,int n){
        if(index==n && (val%index==0 || index%val==0) ){
            res++;
            return;
        }
        // cout<<val<<":"<<index<<endl;
        if(val%index==0 || index%val==0){
            used.insert(val);
            for(int i=1;i<=n;i++){
                if(used.count(i)==0){
                    dfs(i,index+1,n);
                }
            }
            used.erase(val);
        }

    }
public:
    int countArrangement(int n) {
        for(int val=1;val<=n;val++){
            // cout<<"START:\n";
            dfs(val,1,n);
        }
        return res;
    }
};