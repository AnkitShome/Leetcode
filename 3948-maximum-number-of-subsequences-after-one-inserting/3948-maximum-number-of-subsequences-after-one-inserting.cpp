class Solution {
public:
    long long numOfSubsequences(string s) {
        long long n=s.size();
        vector<long long> prefL(n),prefLC(n),sufT(n),sufCT(n);
        for(long long i=n-1;i>=0;i--){
            if(i<n-1)   sufT[i]=sufT[i+1];
            if(s[i]=='T')   sufT[i]++;
        }
        for(long long i=n-1;i>=0;i--){
            if(i<n-1)   sufCT[i]=sufCT[i+1];
            if(s[i]=='C')   sufCT[i]+=sufT[i];
        }
        for(long long i=0;i<n;i++){
            if(i)   prefL[i]=prefL[i-1];
            if(s[i]=='L')   prefL[i]++;
        }
        for(long long i=0;i<n;i++){
            if(i)   prefLC[i]=prefLC[i-1];
            if(s[i]=='C')   prefLC[i]+=prefL[i];
        }
       
        long long now=0;

        for(long long i=0;i<n;i++){
            if(s[i]=='C')
            now+=(prefL[i]*sufT[i]);
        }

        long long ways=0,ans=0;
        for(long long i=0;i<n;i++){
            long long L=sufCT[i];
            long long C=prefL[i]*sufT[i];
            long long T=prefLC[i];

            ways=max({L,T,C});
            ans=max(ans,ways);
        }
        return now+ans;
    }
};