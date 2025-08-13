class Solution {
public:
    
    int n;
    int dp[2005][2005];

    bool f(int ind,int jump,vector<int>& stones){
        if(ind==n-1)  return true;

        bool possible=0;

        if(dp[ind][jump]!=-1)   return dp[ind][jump];

        for(int j=jump-1;j<=jump+1;j++){
            if(j<=0)    continue;
            int it=lower_bound(stones.begin(),stones.end(),stones[ind]+j)-stones.begin();
            if(it==n)   continue;
            if(stones[it]==stones[ind]+j){
                bool can=f(it,j,stones);
                possible|=can;
            }
        }

        return dp[ind][jump]=possible;
    }

    bool canCross(vector<int>& stones) {
        n=stones.size();
        if(stones[1]-stones[0]>1)   return false;
        memset(dp,-1,sizeof(dp));
        return f(1,1,stones);
    }
};

// 0 1 2 3 4 5 6  7
// 0 1 3 5 6 8 12 17
            //6->8 using 2 steps    

            //ind=5 or stones[ind]=8 using jump=2
            //it=low(,j)  j=1,2,3
            //it=6 sontes[it]!=stones[ind]+j

