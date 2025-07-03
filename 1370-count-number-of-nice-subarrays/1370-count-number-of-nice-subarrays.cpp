class Solution {
public:
    int f(vector<int> & nums,int k){
        if(k<0) return 0;
        int n=nums.size();
        int l=0,r=0,count=0,sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto &i:nums)   {
            if(i&1) i=1;
            else    i=0;
        }
        return f(nums,k)-f(nums,k-1);
    }
};