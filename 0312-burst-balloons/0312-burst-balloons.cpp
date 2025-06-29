class Solution {
public:

    int n;
    int dp[305][305];

    int f(int l,int r,vector<int>& pop){
        if(abs(r-l)<=1)  return 0;

        if(dp[l][r]!=-1)    return dp[l][r];

        int ans=0;

        for(int i=l+1;i<=r-1;i++){
            int cur=pop[l]*pop[i]*pop[r];
            int next=f(l,i,pop)+f(i,r,pop);
            ans=max(ans,next+cur);
        }
        return dp[l][r]=ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> pop(nums.size()+2);
        n=nums.size();
        pop[0]=pop[n+1]=1;
        for(int i=1;i<=n;i++)   pop[i]=nums[i-1];   
        memset(dp,-1,sizeof(dp));
        return f(0,n+1,pop);
    }
};