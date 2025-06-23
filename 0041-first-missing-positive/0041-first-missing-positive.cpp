class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0 or nums[i]>n) nums[i]=n+1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==n+1) {continue;}
            int num=abs(nums[i]);
            num--;
            if(num==n)   continue;
            nums[num]=-abs(nums[num]);
        }
        for(auto i:nums)    cout<<i<<" ";
        for(int i=0;i<n;i++){
            if(nums[i]>=0)   return i+1;
        }
        return n+1;
    }
};