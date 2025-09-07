class Solution {
public:
    int n;
    unordered_map<int,int> dp;
    int dfs(int i,vector<vector<int>>& jobs,vector<int>& start){
        if(i==n)  return 0;
        if(dp.count(i))   return dp[i];
        int it=lower_bound(start.begin(),start.end(),jobs[i][1])-start.begin();
        int pick=jobs[i][2]+dfs(it,jobs,start);
        int not_pick=dfs(i+1,jobs,start);
        return dp[i]=max(pick,not_pick);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        sort(startTime.begin(),startTime.end());
        return dfs(0,jobs,startTime);
    }
};