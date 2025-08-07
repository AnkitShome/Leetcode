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
        memset(dp,-1,sizeof(dp));
        return f(0,-1,nums);
    }
};