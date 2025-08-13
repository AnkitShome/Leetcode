class Solution {
public:
    
    unordered_map<int,vector<string>> dp;
    unordered_set<string> words;
    int n;

    vector<string> f(int start,string s){
        vector<string> ans;
        if(start==n){
            ans.push_back("");
            return ans;
        }

        vector<string> res;
        
        for(int end=start+1;end<=n;end++){
            string temp=s.substr(start,end-start);
            if(words.count(temp)){
                vector<string> next=f(end,s);

                for(int i=0;i<next.size();i++){
                    string jazz=next[i];
                    if(jazz=="")    ans.push_back(temp);
                    else    ans.push_back(temp+" "+jazz);
                }
            }
        }
        return ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for(auto i:wordDict)    words.insert(i);
        vector<string> ans=f(0,s);
        return ans;
    }
};