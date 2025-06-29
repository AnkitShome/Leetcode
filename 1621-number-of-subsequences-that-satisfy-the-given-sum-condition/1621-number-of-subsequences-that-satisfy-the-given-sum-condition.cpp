class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=n-1;

        int ans=0;
        vector<int> pow(n+1);
        int mod=1e9+7;

        pow[0]=1;
        for(int i=1;i<=n;i++)   pow[i]=(pow[i-1]%mod*2)%mod;
        
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                int ways=pow[r-l];
                l++;
                ans=(ans%mod+ways%mod)%mod;
            }
            else    r--;
        }

        return ans;
    }
};