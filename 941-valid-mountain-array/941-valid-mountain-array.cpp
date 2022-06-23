class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)         // min required size of array is 3
            return false;
        int left = 0, right = arr.size()-1;      
        while(left<arr.size()-1 && arr[left]<arr[left+1])
                left++;         // climb from left
        while(right>0 && arr[right]<arr[right-1])
                right--;        // climb from right
        
        // return true if both climbers meet and neither is at their original start points
        if(left==right && left!=0 && right!= arr.size()-1)
            return true;        
        return false; 
        
    }
};