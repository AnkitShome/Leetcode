class Solution {
public:
    int n;

    int dp[301][11];

    int f(int i,int d,vector<int> &job){
        if(i==n and d==0)   return 0;
        if(i==n)    return 1e7;
        if(d==0)    return 1e7;

        if(dp[i][d]!=-1)    return dp[i][d];

        int dif=-1;
        int ans=1e7;
        for(int j=i;j<n;j++){
            dif=max(dif,job[j]);
            int next=f(j+1,d-1,job);
            ans=min(ans,dif+next);
        }    
        return dp[i][d]=ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n=jobDifficulty.size();
        if(d>n) return -1;
        memset(dp,-1,sizeof(dp));
        return f(0,d,jobDifficulty);
    }
};