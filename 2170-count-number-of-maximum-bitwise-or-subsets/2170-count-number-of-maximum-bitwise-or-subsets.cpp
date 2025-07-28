class Solution {
public:

    int n;
    int s;
    int dp[16][131073];
    int f(int ind,int state,vector<int> &nums){
        if(ind==n){
            if(state==s)    return 1;
            return 0; 
        }
        if(dp[ind][state]!=-1)  return dp[ind][state];
        int not_take=f(ind+1,state,nums);
        int take=f(ind+1,state|nums[ind],nums);
        return dp[ind][state]=take+not_take;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        s=0;
        n=nums.size();
        for(auto i:nums)    s=s|i;
        memset(dp,-1,sizeof(dp));
        return f(0,0,nums);
    }
};