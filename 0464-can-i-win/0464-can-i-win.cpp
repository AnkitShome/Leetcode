class Solution {
public:
    
    int n,m;

    int f(int sum,int used,map<pair<int,int>,int>& dp ){
        if(sum>=m)  return 0;
        if(dp.count({sum,used})) return dp[{sum,used}];
        
        bool moves=0;
        for(int i=1;i<=n;i++){
            if((used&(1<<i))!=0) continue;
            int nextUsed=used|(1<<i); 
            if(sum+i>=m)    moves=1;
            if(!f(sum+i,nextUsed,dp)){
                moves=1;
            }
            if(moves)  return dp[{sum,used}]=1; 
        }
        return dp[{sum,used}]=0;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        n=maxChoosableInteger;
        m=desiredTotal;            
        
        map<pair<int,int>,int> dp;

        int maxm=n*(n+1)/2;

        if(m>maxm)  return false;
        if(m==0)    return true;
        int ans=f(0,0,dp);
        if(ans)   return true;
        return false;
    }
};