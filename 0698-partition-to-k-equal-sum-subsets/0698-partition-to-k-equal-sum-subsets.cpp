class Solution {
public:
    int n;
    unordered_map<int,bool> dp;

    bool f(int sum,int bit,int k,int target,vector<int> &nums){
        if(k==0)    return true;

        if(dp.count(bit))   return dp[bit];

        for(int i=0;i<n;i++){
            if(!(bit & (1<<i))){
                if(sum+nums[i]==target)
                    if(f(0,bit | (1<<i),k-1 ,target,nums))  return dp[bit]=true;
                if(sum+nums[i]<target)
                    if(f(sum+nums[i],bit | (1<<i), k, target,nums)) return dp[bit]=true;
            }
        }
        return dp[bit]=false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size();
        int total=0;
        for(auto i:nums)    total+=i;
        if(total%k) return false;
        int sum=total/k;
        for(auto i:nums)    if(i>sum)   return false;
        int bits=0;
        return f(0,0,k,sum,nums);
    }
};