class Solution {
public:
    int n;
    bool isSquare(int n){
        if(n==0)    return true;
        for(int i=1;i*i<=n;i++){
            if(n==(i*i))    return true;    
        }
        return false;
    }

    int dfs(int last,int mask,vector<int>& nums){
        if(mask==(1<<n)-1){
            return 1;
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(i==last or (mask & (1<<i)))  continue;

            if(i>0 and nums[i]==nums[i-1] and !(mask & (1<<i-1)))  {
                continue;
            }
            if(last==-1){
                int res=dfs(i,mask|(1<<i),nums);
                ans+=res;
                continue;
            }

            int sum=nums[last]+nums[i];
            if(!isSquare(sum))  continue;

            int res=dfs(i,mask | (1<<i), nums);
            ans+=res;
        }

        return ans;
    }

    int numSquarefulPerms(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=dfs(-1,0,nums);
        return ans;
    }
};