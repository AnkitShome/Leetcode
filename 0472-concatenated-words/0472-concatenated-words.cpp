class Solution {
public:

    set<string> mp;
    int f(int ind,int count,string s,vector<int>&dp){
        int n=s.size();
        if(ind==n){
            if(count>1) return 1;
            return 0;
        }
        if(dp[ind]!=-1)  return dp[ind];
        int res=0;
        for(int i=ind;i<n;i++){
            string temp=s.substr(ind,i-ind+1);
            if(mp.find(temp)==mp.end()) continue;
            res=res | f(i+1,count+1,s,dp);
        }
        return dp[ind]=res;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto i:words)   mp.insert(i);
        vector<string> ans;
        for(auto s:words){
            mp.erase(s);
            int n=s.size();
            vector<int> dp(n,-1);
            int possible=f(0,0,s,dp);
            if(possible)    ans.push_back(s);
            mp.insert(s);
        }
        return ans;
    }

};