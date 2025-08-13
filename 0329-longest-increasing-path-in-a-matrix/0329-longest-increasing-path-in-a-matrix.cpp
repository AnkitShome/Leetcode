class Solution {
public:

    vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};

    int n,m;
    int dp[200][200];

    bool isValid(int i,int j){
        if(i<0 or j<0 or i>=n or j>=m)  return false;
        return true;
    }

    int dfs(int i,int j,vector<vector<int>>& matrix){
        if(dp[i][j]!=-1)    return dp[i][j];
        int count=1;

        for(int k=0;k<4;k++){
            int nx=i+dirs[k].first;
            int ny=j+dirs[k].second;
            if(!isValid(nx,ny)) continue;
            if(matrix[nx][ny]<=matrix[i][j])    continue;
            int rem=dfs(nx,ny,matrix);
            count=max(count,rem+1);
        }
        return dp[i][j]=count;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size(),m=matrix[0].size();
        int ans=1;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dfs(i,j,matrix));
            }
        }
        return ans;
    }
};