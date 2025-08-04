class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int l=-1;
        priority_queue<pair<int,int>> maxi;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mint;
        
        int ans=0;

        for(int r=0;r<n;r++){
            while(!maxi.empty() and abs(maxi.top().first-nums[r])>limit){
                l=max(l,maxi.top().second);
                maxi.pop();
            }
            while(!mint.empty() and abs(mint.top().first-nums[r])>limit){
                l=max(l,mint.top().second);
                mint.pop();
            }
            maxi.push({nums[r],r});
            mint.push({nums[r],r});
            ans=max(ans,r-l);
        }
        return ans;
    }
};