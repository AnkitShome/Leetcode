class Solution {
public:
    int dp[105][105];

    int f(int l,int r,vector<int>&cuts){
        if(abs(l-r)<=1) return 0;
        if(dp[l][r]!=-1)    return dp[l][r];
    
        int res=1e9;

        for(int i=l+1;i<r;i++){
            int length=cuts[r]-cuts[l];
            int cut=f(l,i,cuts)+f(i,r,cuts);
            res=min(length+cut,res);
        }
        return dp[l][r]=res;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<int> pos;
        sort(cuts.begin(),cuts.end());
        pos.push_back(0);
        for(auto cut:cuts)  pos.push_back(cut);
        pos.push_back(n);
        memset(dp,-1,sizeof(dp));
        return f(0,cuts.size()+1,pos);
        return -1;
    }
};