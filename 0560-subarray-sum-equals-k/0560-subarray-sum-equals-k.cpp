class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;

        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans+=mp[sum-k];
            mp[sum]++;
            if(sum==k)  ans++;
        }
        return ans;
    }
};