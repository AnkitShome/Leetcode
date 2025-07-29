class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        int ans=0;
        vector<int> vis(256,-1);
        while(j<n){
            if(vis[s[j]]!=-1){
                int l=vis[s[j]];
                i=max(i,l+1);
            }
            vis[s[j]]=j;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};