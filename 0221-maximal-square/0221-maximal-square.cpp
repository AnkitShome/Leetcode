class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> ones(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j-1>=0)  ones[i][j]+=ones[i][j-1];
                if(i-1>=0)  ones[i][j]+=ones[i-1][j];
                if(i-1>=0 and j-1>=0)   ones[i][j]-=ones[i-1][j-1];
                if(matrix[i][j]=='1')   ones[i][j]++;
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int l=0;l<min(n,m);l++){
                    if(i+l>=n or j+l>=m)    continue;
                    int val=ones[i+l][j+l];
                    if(i-1>=0)  val-=ones[i-1][j+l];
                    if(j-1>=0)  val-=ones[i+l][j-1];
                    if(i-1>=0 and j-1>=0)   val+=ones[i-1][j-1];
                    if(val==(l+1)*(l+1))    ans=max(ans,val);    
                }
            }
        }

        return ans;
    }
};