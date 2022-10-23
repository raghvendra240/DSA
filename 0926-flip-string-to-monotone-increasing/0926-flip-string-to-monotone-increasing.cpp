class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
      int n  = s.size();
      int zerosTillNow[n];
      int onesTillNow[n];
      int totalZeros = 0;
      int totalOnes = 0;
      zerosTillNow[0] = 0;
      onesTillNow[0] = 0;
      for (int i = 0; i < n; i++) {
          if (i > 0) {
             onesTillNow[i] = onesTillNow[i-1];
             zerosTillNow[i] = zerosTillNow[i-1];  
          }
        if (s[i] == '0') {
            zerosTillNow[i] += 1 ;
            totalZeros++;
        } else {
            onesTillNow[i] += 1;
            totalOnes++;
        }
          // cout<<zerosTillNow[i]<<":"<<onesTillNow[i]<<endl;
      }

      int res = min(totalOnes, totalZeros);
      if (totalOnes == 0 || totalZeros == 0) return 0;

      for (int i = 0; i <n;i++){
            int onesOnLeft  = onesTillNow[i];
            int zerosOnRight = totalZeros - zerosTillNow[i];
          // cout<<totalZeros<<"-"<<zerosTillNow[i]<<endl;
          // cout<<onesOnLeft<<"--"<<zerosOnRight<<endl;
            res = min(res,onesOnLeft+zerosOnRight);
      }

      return res;
        
    }
};