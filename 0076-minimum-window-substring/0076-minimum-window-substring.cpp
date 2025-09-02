class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,n=s.size(),j=0;
        if(s.size()<t.size())   return "";
        unordered_map<int,int> mp;
        for(auto i:t)   mp[i]++;

        int ans=1e9;
        int ind=-1;

        unordered_map<int,int> dp;
        int count=0;
        while(j<n){
            dp[s[j]]++;
            if(mp.count(s[j]) and dp[s[j]]==mp[s[j]])  count++;
            
            while(i<=j and count==mp.size()){
                if(count==mp.size()){
                    if(j-i+1<ans){
                        ans=j-i+1;
                        ind=i;
                    }
                }
                if(!mp.count(s[i])) {dp[s[i]]--;i++;continue;}
                else if(dp[s[i]]>mp[s[i]])   {dp[s[i]]--;i++;continue;}
                else if(dp[s[i]]==mp[s[i]])  break;
            }
            j++;
        }
        if(ans==1e9)    return "";
        return s.substr(ind,ans);
    }
};