class Solution {
public:

    int dp[305][305];
    int N,p;
    int MOD=1e9+7;

    long long f(int ind,int sum){
        if(sum==0)  return 1;
        if(ind>sum)   return 0;

        if(dp[ind][sum]!=-1)    return dp[ind][sum];

        long long skip=f(ind+1,sum);
        long long take=0;

        long long power=pow(ind,p);
        if(sum>=power)  take=f(ind+1,sum-power);
        
        return dp[ind][sum]=(take+skip)%MOD;
    }


    int numberOfWays(int n, int x) {
        N=n;
        p=x;
        memset(dp,-1,sizeof(dp));

        int ans= f(1,n);

        return ans;
    }
};