class Solution {
public:
  
    
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> vis;
        for(int i=0;i<n;i++){
            vis[nums[i]]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int count=1;
            if(vis[nums[i]]==2)   continue;
            int next=nums[i]+1;
            while(vis[next]==1){
                count++;
                next=next+1;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};