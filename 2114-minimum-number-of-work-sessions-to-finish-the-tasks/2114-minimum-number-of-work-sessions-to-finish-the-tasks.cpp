class Solution {
public:
    int n;
    int time;
    int dp[16][(1<<15)];

    int dfs(int t,int mask,vector<int>& task){
        if(mask==(1<<n)-1){
            if(!t)  return 0;
            return 1;
        }

        if(dp[t][mask]!=-1) return dp[t][mask];

        int ans=1e9;

        for(int i=0;i<n;i++){
            if(mask & (1<<i))    {continue;}
            
            int res=0;
            if(task[i]+t<time){
                res=dfs(t+task[i],mask | (1<<i),task);
            }
            else if(task[i]+t>time){
                res=1+dfs(task[i],mask | (1<<i),task);
            }
            else if(task[i]+t==time){
                res=1+dfs(0,mask | (1<<i),task);
            }
            ans=min(ans,res);
        }
        return dp[t][mask]=ans;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        time=sessionTime;
        n=tasks.size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,tasks);
    }
};