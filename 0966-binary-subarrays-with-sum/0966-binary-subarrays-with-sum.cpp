class Solution {
public:
    int f(vector<int>& nums,int k){
        if(k<0)    return 0;
        int n=nums.size();
        int i=0,j=0;
        int sum=0;
        int ans=0;
        while(j<n){
            sum+=nums[j];
            while(sum>k){
                sum-=nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums,goal)-f(nums,goal-1);
    }
};