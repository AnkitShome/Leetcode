class Solution {
public:

    int n;
    vector<vector<int>> dp;
    int f(int i,int s,vector<int> &coins){
        if(i==0){
            if(s%coins[i]==0)   return 1;
            return 0;
        }
        if(dp[i][s]!=-1)    return dp[i][s];
        int skip=f(i-1,s,coins);
        int take=0;
        if(s>=coins[i]){
            take=f(i,s-coins[i],coins);
        }
        return dp[i][s]=skip+take;
    }

    int change(int amount, vector<int>& coins) {
        n=coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,coins);
        return ans;
    }
};