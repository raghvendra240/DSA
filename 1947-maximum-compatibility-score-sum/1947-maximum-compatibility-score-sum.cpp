class Solution {
    vector<int>visitedMentors;
    vector<vector<int>>dp;
    int dfs(int index){
        if(index >= dp.size())
            return 0;
        int ans = 0;
        for(int mentor = 0 ;mentor < dp.size(); mentor++){
                if(visitedMentors[mentor]==false){
                    visitedMentors[mentor] = true;
                    // ans=max(ans,dp[index][mentor]);
                    ans = max(ans, dfs(index+1) + dp[index][mentor]);
                    visitedMentors[mentor] = false;
                }
        }
        return ans;
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n  = students.size();
        int m = students[0].size();
        visitedMentors.resize(n,false);
       dp.resize(n,vector<int>(n,0));
        for(int student=0;student<n;student++){
            for(int mentor=0;mentor<n;mentor++){
                for(int question = 0 ; question < m ; question ++){
                    if(students[student][question] == mentors[mentor][question])
                        dp[student][mentor]++;
                }
            }
        }
        
        return dfs(0);
    }
};