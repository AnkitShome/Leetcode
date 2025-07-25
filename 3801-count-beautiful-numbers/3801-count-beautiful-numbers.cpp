class Solution {
public:

    long long count(int x){
        if(x<1) return 0;
        string s = to_string(x);
        int n = s.size();
        vector<int> digits(n);
        for (int i = 0; i < n; i++) {
            digits[i] = s[i] - '0';
        }
        unordered_map<string,long long> dp;
        return f(0,1,0,0,0,1,digits,n,dp);
    }

    long long f(int pos, int tight, int started, int hasZero, int sum, int prod, vector<int> &digits, int n, unordered_map<string, long long> &dp) {
        if(pos==n){
            if(!started)    return 0;
            if(hasZero) return 1;
            return (prod%sum==0)?1:0;
        }

        string key=to_string(pos)+"_"+(tight?"1":"0")+"_"+(started?"1":"0")+"_"+(hasZero?"1":"0")+"_"+to_string(prod)+"_"+to_string(sum);

        if(dp.find(key)!=dp.end())   return dp[key];

        long long ans=0;        
        int limit=tight?digits[pos]:9;

        if(started and hasZero and !tight){
            long long ways=1;
            for(int i=pos;i<n;i++){
                ways*=10;
            }
            return dp[key]=ways;
        }

        for(int d=0;d<=limit;d++){
            bool newTight=tight and (d==limit);

            if(!started){
                if(d==0){
                    ans+=f(pos+1,newTight,0,0,0,1,digits,n,dp);
                }
                else{
                    ans+=f(pos+1,newTight,1,0,d,d,digits,n,dp);
                }
            }
            else{
                if(hasZero){
                    ans+=f(pos+1,newTight,1,1,sum+d,0,digits,n,dp);
                }
                else{
                    if(d==0){
                        ans+=f(pos+1,newTight,1,1,sum,0,digits,n,dp);
                    }
                    else{
                        ans+=f(pos+1,newTight,1,0,sum+d,prod*d,digits,n,dp);
                    }
                }
            }
        }
        return dp[key]=ans;
    }

    int beautifulNumbers(int l, int r) {
        long long countR = count(r);
        long long countL = count(l - 1);
        return (int)(countR - countL);
    }
};