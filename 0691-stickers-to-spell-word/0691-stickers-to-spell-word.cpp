class Solution {
public:

    int n;
    unordered_map<string,int> dp;

    string encode(vector<int>& freq){
        string res="";
        for(auto j:freq){
            res+=to_string(j)+"_";
        }
        return res;
    }

    int f(vector<vector<int>>& check,vector<int>& freq){
        int can=0;
        for(auto j:freq){
            if(j)   {can=1;continue;}
        }

        if(!can)    return 0;

        string key=encode(freq);
        if(dp.count(key))   return dp[key];

        int pivot=-1;
        for(int j=0;j<26;j++){
            if(freq[j]) {pivot=j;break;}
        }

        int ans=1e9;

        for(int i=0;i<n;i++){
            if(check[i][pivot]==0)  continue;
            bool use=0;
            for(int j=0;j<26;j++){
                if(check[i][j] and freq[j])  {use=1;continue;}
            }
            if(!use)    continue;

            vector<int> ref(freq);
            for(int j=0;j<26;j++){
                ref[j]=max(0,freq[j]-check[i][j]);
            }

            int res=1+f(check,ref);
            ans=min(ans,res);
        }

        return dp[key]=ans;
    }

    int minStickers(vector<string>& stickers, string target) {
        vector<int> freq(26);
        for(auto i:target)  freq[i-'a']++;

        vector<string> needed;

        for(int i=0;i<stickers.size();i++){
            int can=0;
            string s=stickers[i];
            for(auto x:s){
                if(freq[x-'a']) can=1;
            }
            if(can) needed.push_back(s);
        }

        n=needed.size();
        vector<vector<int>> check(n,vector<int>(26));

        
        for(int i=0;i<needed.size();i++){
            for(auto j:needed[i]){
                check[i][j-'a']++;
            }
        }
        
        int ans=f(check,freq);
        if(ans>=1e9)    return -1;
        return ans;
    }
};