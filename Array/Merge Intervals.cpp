https://www.interviewbit.com/problems/merge-intervals/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {

int n=intervals.size();

if(n==0)
  return {newInterval};
    
        
    vector<Interval>res;

   
     int i=0;
     
     
     //all interval that comes before newInterval
     
     while(i<n && intervals[i].end<newInterval.start)
     {
         res.push_back(intervals[i]);
         i++;

     }
     
     
     merging inetrvals which are overlapping with newInterval
     while(i<n && intervals[i].start<=newInterval.end)
     {
         newInterval.start=min(intervals[i].start,newInterval.start);
         newInterval.end=max(intervals[i].end,newInterval.end);
         i++;
     }
     
     res.push_back(newInterval);
     
     // add remaining interval at end
     while(i<n)
     {
         res.push_back(intervals[i]);
         i++;
     }
    
    
    return res;
      
    
}
