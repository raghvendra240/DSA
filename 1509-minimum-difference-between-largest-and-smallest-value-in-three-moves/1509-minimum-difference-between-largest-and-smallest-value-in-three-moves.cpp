class Solution {
public:
    int minDifference(vector<int>& nums) {
        /*
                If we can do 0 move, return max(A) - min(A)
        If we can do 1 move, return min(the second max(A) - min(A), the max(A) - second min(A))
        and so on.


        Explanation
        We have 4 plans:

        kill 3 biggest elements
        kill 2 biggest elements + 1 smallest elements
        kill 1 biggest elements + 2 smallest elements
        kill 3 smallest elements

        */
        
        int n = nums.size();
        if (n < 5) return 0;
        sort(nums.begin(), nums.end());
        return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
        
    }
};