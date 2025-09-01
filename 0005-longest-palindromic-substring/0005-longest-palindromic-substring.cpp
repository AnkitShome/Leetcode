class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();

        auto f=[&](int l,int r){
            int i=r,j=l;
            while(l>=0 and r<n and s[l]==s[r]){
                l--;
                r++;
            }
            return make_pair(l+1,r-1);
        };

        int res=0;
        pair<int,int> ans;

        for(int i=0;i<n;i++){
            auto op=f(i,i);
            int len=op.second-op.first+1;
            if(len>res){
                ans=op;
                res=len;
            }
            op=f(i,i+1);
            len=op.second-op.first+1;
            if(len>res){
                ans=op;
                res=len;
            }
        }
        string x=s.substr(ans.first,ans.second-ans.first+1);
        return x;
    }
};