class Solution {
public:
    int n;
    long long f(int ind,int x,int k,int prod,vector<int> &nums,vector<vector<long long>> &dp){
        if(ind==n){
            return 0;
        }

        long long fw=0,nw=0;

        if(dp[ind][prod+1]!=-1)  return dp[ind][prod+1];

        long long ans=0;
        if(prod==-1){
            if(nums[ind]==x)    ans++;
            fw=ans+f(ind+1,x,k,nums[ind],nums,dp);
            nw=f(ind+1,x,k,-1,nums,dp);
        }
        else{
            int rem=(prod*nums[ind])%k;
            if(rem==x)  ans++;
            fw=ans+f(ind+1,x,k,(prod*nums[ind])%k,nums,dp);
        }

        return dp[ind][prod+1]=fw+nw;
    }
    vector<long long> resultArray(vector<int>& nums, int k) {
        n=nums.size();
        for(auto &i:nums)   i%=k;
        vector<long long> res(k);
        for(int j=0;j<k;j++){
            vector<vector<long long>> dp(n,vector<long long>(k+1,-1));
            res[j]=f(0,j,k,-1,nums,dp);
        }
        return res;
    }
};