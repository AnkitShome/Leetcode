class Solution {
public:
    int maxDistance(string s, int k) {
        int N=0,E=0,W=0,S=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='N')  N++;
            if(s[i]=='E')  E++;
            if(s[i]=='W')  W++;
            if(s[i]=='S')  S++;

            int y=abs(N-S);
            int x=abs(W-E);

            int d=x+y;
            int inc=min(2*k,i+1-d);

            ans=max(ans,d+inc);
        }
        return ans;
    }
};