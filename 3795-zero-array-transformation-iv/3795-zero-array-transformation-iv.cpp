class Solution {
public:
    int n;
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n=queries.size();
        int trophy=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            vector<vector<int>> dp(n+1,vector<int>(num+1,1e9));

            for(int ind=0;ind<=n;ind++)  dp[ind][0]=ind;

            for(int ind=n-1;ind>=0;ind--){
                for(int val=1;val<=num;val++){
                    int skip=dp[ind+1][val];
                    int take=1e9;
                    
                    int l = queries[ind][0];
                    int r = queries[ind][1];
                    int v = queries[ind][2];


                    if(val>=v and i>=l and i<=r){
                        take=dp[ind+1][val-v];
                    }
                    dp[ind][val]=min(take,skip);
                }
            }
            int res=dp[0][num];
            trophy=max(trophy,res);     
            if(trophy>=1e9) return -1;
        }
        return trophy;
    }
};