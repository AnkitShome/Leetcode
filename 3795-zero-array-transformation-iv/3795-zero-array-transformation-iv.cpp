class Solution {
public:
    int n;
    
    int f(int ind,int i,int num,vector<vector<int>>& dp,vector<vector<int>>& queries){
        if(num==0)  return ind;
        if(ind==n)  return 1e9;

        if(dp[ind][num]!=-1)    return dp[ind][num];

        int skip=f(ind+1,i,num,dp,queries);
        int take=1e9;
        
        int l = queries[ind][0];
        int r = queries[ind][1];
        int v = queries[ind][2];


        if(num>=v and i>=l and i<=r){
            take=f(ind+1,i,num-v,dp,queries);
        }
        return dp[ind][num]=min(take,skip);

    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n=queries.size();
        int trophy=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            vector<vector<int>> dp(n,vector<int>(num+1,-1));
            int res=f(0,i,num,dp,queries);
            trophy=max(trophy,res);     
            if(trophy>=1e9) return -1;
        }
        return trophy;
    }
};