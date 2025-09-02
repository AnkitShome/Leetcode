class Solution {
public:
    int f(vector<int>& nums,int k){
        if(k<=0)    return 0;
        int n=nums.size();
        unordered_map<int,int> mp;
        int i=0,j=0;
        int count=0;
        int ans=0;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]==1) count++;

            while(count>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)  {count--;mp.erase(nums[i]);}
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};