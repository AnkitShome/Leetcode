class Solution {
public:

    int n,k;
    vector<vector<int>> dp;
    
    int f(int i,int count,vector<int> &prefix){
        if(i==n+1 and count==0)   return 0;

        if(i==n+1)    return INT_MAX;
        if(count==0)    return INT_MAX;

        if(dp[i][count]!=-1)    return dp[i][count];

        int ans=INT_MAX;

        int maxm=0;
        for(int j=i;j<=n;j++){
            int till=prefix[j]^prefix[i-1];
            int next=f(j+1,count-1,prefix);
            
            if(next!=INT_MAX)
                ans=min(ans,max(till,next));
            
        }
        return dp[i][count]= ans;
    }
    
    int minXor(vector<int>& nums, int k) {
        n=nums.size();
        dp.assign(n+1,vector<int>(k+1,-1));
        vector<int> prefix(n+1);
        for(int i=0;i<n;i++) prefix[i+1]=prefix[i]^nums[i];
        return f(1,k,prefix);
    }
};