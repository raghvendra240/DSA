class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        /*
        refer this->https://leetcode.com/problems/subarray-product-less-than-k/submissions/
        */
        long long res=1;
        int start=0;
        for(int end=1;end<prices.size();end++){
            if(prices[end]+1!=prices[end-1]){
                res++;
                start=end;
            }else{
                res+=(end-start+1);
            }
        }
        return res;
    }
};