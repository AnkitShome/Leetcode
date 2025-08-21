class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> prefix(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0) prefix[i][j]+=prefix[i-1][j];
                if(j>0) prefix[i][j]+=prefix[i][j-1];
                if(i and j) prefix[i][j]-=prefix[i-1][j-1];
                if(matrix[i][j]==1) prefix[i][j]++;
            }
        }
        int r=min(n,m);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<min(n,m);k++){
                    if(i+k>=n or j+k>=m)    continue;
                    int sum=prefix[i+k][j+k];
                    int top=0,left=0,add=0;
                    if(i-1>=0)
                        top=prefix[i-1][j+k];
                    if(j-1>=0)
                        left=prefix[i+k][j-1];
                    if(i-1>=0 and j-1>=0)
                        add=prefix[i-1][j-1];
                    sum=sum-top-left+add;
                    if(sum==(k+1)*(k+1))    ans++;
                }
            }
        }
        return ans;
    }
};