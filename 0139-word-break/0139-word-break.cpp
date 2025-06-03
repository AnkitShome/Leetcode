class Solution {
public:
    int n;
    int dp[301][302];
    bool f(int ind,int last,string s,set<string> &word){
        if(ind==n and ind==last+1)    return 1;
        if(ind==n)  return 0;
        if(dp[ind][last+1]!=-1)   return dp[ind][last+1];
        string res=s.substr(last+1,ind-last);
        int take=0;
        int skip=f(ind+1,last,s,word);
        if(word.find(res)!=word.end()){
            take=f(ind+1,ind,s,word);
        }
        return dp[ind][last+1]=take | skip;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        set<string> word;
        memset(dp,-1,sizeof(dp));
        for(auto i:wordDict)    word.insert(i);
        return f(0,-1,s,word);
    }
};