class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int res;
        int tempRes=0;
        for(int i=0;i<n;i++){
         if(!grumpy[i]){
            tempRes+=customers[i];
         }
        }
        res=tempRes;
        for(int i=0;i<minutes;i++){
         if(grumpy[i]){
            tempRes+=customers[i];
         }
        }
        res=max(res,tempRes);
        int start=0;
        for(int end=minutes;end<n;end++,start++){
         if(grumpy[end]){
            tempRes+=customers[end];
         }
         if(grumpy[start]){
            tempRes-=customers[start];
         }
         res=max(res,tempRes);
        }
        res=max(res,tempRes);
        return res;
    }
};