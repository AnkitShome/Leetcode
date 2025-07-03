class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int> mp;
        
        int sum=0,ans=0;

        for(auto i:nums){
            sum+=i;
            if(sum==goal)   ans++;
            ans+=mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};