class Solution {
public:
    int n;

    int maximumLength(vector<int>& nums, int k) {
        int ans=-1;
        n=nums.size();            
        vector<unordered_map<int,int>> dp(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int rem=(nums[i]+nums[j])%k;
                if(dp[i].count(rem))  dp[j][rem]=max(dp[j][rem],1+dp[i][rem]);
                else    dp[j][rem]=max(dp[j][rem],2);
                ans=max(ans,dp[j][rem]);
            }
        }
        return ans;
    }
};