class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int m=1e5,M=-1e5;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            while(l<r){
                if(nums[l]+nums[r]<=target-nums[i]){
                    M=max(M,nums[l]+nums[r]+nums[i]);
                    l++;
                }
                else if(nums[l]+nums[r]>target-nums[i]){
                    m=min(nums[l]+nums[r]+nums[i],m);
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        if(abs(M-target)<abs(target-m)) return M;
        return m;
    }
};