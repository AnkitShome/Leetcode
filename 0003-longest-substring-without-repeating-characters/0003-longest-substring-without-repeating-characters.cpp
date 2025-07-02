class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        int ans=0;
        vector<int> vis(256,-1);
        while(i<n){
            if(vis[s[i]]!=-1){
                int l=vis[s[i]];
                if(l>=j) j=l+1;
            }
            vis[s[i]]=i;
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};