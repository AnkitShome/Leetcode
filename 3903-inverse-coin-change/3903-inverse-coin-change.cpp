class Solution {
public:

    int f(int i,int s,vector<int>& coins,vector<vector<int>>& dp){
        if(i==0){
            if(s%coins[i]==0)  return 1;
            return 0;
        }
        if(dp[i][s]!=-1)    return dp[i][s];
        int skip=f(i-1,s,coins,dp);
        int take=0;
        if(s>=coins[i]){
            take=f(i,s-coins[i],coins,dp);
        }
        return dp[i][s]=take+skip;
    }


    vector<int> findCoins(vector<int>& numWays) {
        int n=numWays.size();
        vector<int> ways(numWays);
        vector<int> coins;
        
        for(int i=0;i<n;i++){
            if(coins.size()==0){
                if(ways[i]==1)  coins.push_back(i+1);
                if(ways[i]>1)   break;
                continue;
            }   

            vector<vector<int>> dp(coins.size(),vector<int>(i+2,-1)); 
            
            int till_now=f(coins.size()-1,i+1,coins,dp);
            if(ways[i]<till_now or ways[i]>till_now+1)  {coins.resize(0);break;}
            if(ways[i]==till_now+1){
                coins.push_back(i+1);
            }
        }

        return coins;
    }
};