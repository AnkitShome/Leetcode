class Solution {
public:

    set<string> mp;
    int f(int ind,string s,vector<int>&dp){
        int n=s.size();
        if(ind==n){
            return 1;
        }
        if(dp[ind]!=-1)  return dp[ind];
        int res=0;
        for(int i=ind;i<n;i++){
            string temp=s.substr(ind,i-ind+1);
            if(mp.find(temp)==mp.end()) continue;
            if(f(i+1,s,dp)==1){
                return dp[ind]=1;
            }
        }
        return dp[ind]=0;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto i:words)   mp.insert(i);
        vector<string> ans;
        for(auto s:words){
            mp.erase(s);
            int n=s.size();
            vector<int> dp(n,-1);
            int possible=f(0,s,dp);
            if(possible)    ans.push_back(s);
            mp.insert(s);
        }
        return ans;
    }

};