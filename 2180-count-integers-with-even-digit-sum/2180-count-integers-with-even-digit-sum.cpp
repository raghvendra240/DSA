class Solution {
public:
    int countEven(int num) {
        /*
        If sum of digits of num is even
        */
          // creating a backup of num to use it later
        int numBackup = num;
        
        // generating the sum of the digits of the num
        int sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }
        
        // if sum is odd, return (numBackup-1)/2 as per the pattern we found
        if(sum%2) return (numBackup-1)/2;
        
        // if sum is even, return numBackup/2
        else return numBackup/2;
    }
};