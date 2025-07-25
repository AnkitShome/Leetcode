class Solution {
public:

    int f(int pos,int tight,int started,int one,vector<int> &digits,int n,unordered_map<string,int> &dp){
        if(pos==n){
            if(!started)    return 0;
            return one;
        }

        string key=to_string(pos)+"_"+(tight?"1":"0")+"_"+(started?"1":"0")+"_"+to_string(one);

        if(dp.find(key)!=dp.end()) return dp[key];

        int limit=tight? digits[pos]:9;

        int ans=0;

        for(int d=0;d<=limit;d++){
            int newTight=tight and (d==limit);
            int newStarted=started or (d>0);
            int newOne=one+(d==1?1:0);

           ans += f(pos + 1, newTight, newStarted, newOne, digits, n, dp);
        }

        return dp[key]=ans;

    }

    int countDigitOne(int n) {
        if(n<1) return 0;
        string s=to_string(n);
        vector<int> digits;
        int m=s.size();
        for(int i=0;i<m;i++){
            digits.push_back(s[i]-'0');
        }
        unordered_map<string,int> dp;
        return f(0,1,0,0,digits,m,dp);
    }   
};