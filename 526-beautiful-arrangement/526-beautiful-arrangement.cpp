class Solution {
    int seen=0;
    int res=0;
    void dfs(int val,int index,int n){
        if(index==n && (val%index==0 || index%val==0) ){
            res++;
            return;
        }
        if(val%index==0 || index%val==0){
            int temp = 1 << val;
            seen= seen^temp;
            for(int i=1;i<=n;i++){
                if((seen & (1<<i))==0){
                    dfs(i,index+1,n);
                }
            }
            seen= seen^temp;
        }
    }
public:
    int countArrangement(int n) {
        for(int val=1;val<=n;val++){
            dfs(val,1,n);
        }
        return res;
    }
};