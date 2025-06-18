class Solution {
public:
    int n;
    int dp[100005][3][2];

    int f(int cur,int count,int buy,vector<int> &prices){
        if(cur==n or count==2)  return 0;
        if(dp[cur][count][buy]!=-1) return dp[cur][count][buy];
        int skip=f(cur+1,count,buy,prices);
        int profit=0;
        if(buy==1){
            profit=-prices[cur]+f(cur+1,count,0,prices);
        }
        else{
            profit=prices[cur]+f(cur+1,count+1,1,prices);
        }
        return dp[cur][count][buy]=max(skip,profit);
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();   
        memset(dp,-1,sizeof(dp));
        return f(0,0,1,prices); 
    }
};