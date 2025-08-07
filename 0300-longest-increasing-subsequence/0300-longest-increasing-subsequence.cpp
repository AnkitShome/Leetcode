class Solution {
public:
    int dp[2505][2505];
    int n;

    int f(int ind,int prev,vector<int> &nums){
        if(ind==n)  return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int not_take=f(ind+1,prev,nums);
        int take=0;
        if(prev==-1 or nums[ind]>nums[prev]){
            take=1+f(ind+1,ind,nums);
        }
        return dp[ind][prev+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(dp,0,sizeof(dp));
        // return f(0,-1,nums);
        
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int not_take=dp[ind+1][prev+1];
                int take=0;
                if(prev==-1 or nums[ind]>nums[prev])
                    take=1+dp[ind+1][ind+1];
                dp[ind][prev+1]=max(take,not_take);
            }
        }
        return dp[0][0];
    }
};