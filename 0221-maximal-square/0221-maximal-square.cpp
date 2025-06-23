class Solution {
public:

    vector<vector<int>> dp;
    int n,m;

    int f(int i,int j,vector<vector<char>>& matrix){
        if(i==n)    return 0;
        if(j==m)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];

        int right=f(i,j+1,matrix);
        int down=f(i+1,j,matrix);
        int dia=f(i+1,j+1,matrix);
        int ans=0;
        if(matrix[i][j]=='0')   ans=0;
        else    ans=min({right,down,dia})+1;
        return dp[i][j]=ans;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        dp.resize(n,vector<int>(m,-1));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 or j==m-1){
                    if(matrix[i][j]=='1')   dp[i][j]=1;
                    else    dp[i][j]=0;
                }
                else if(matrix[i][j]=='0')   dp[i][j]=0;
                else{
                    dp[i][j]=min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]})+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};