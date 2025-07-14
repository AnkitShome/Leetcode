class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        queue<array<int,3>> q;
        vector<vector<int>> dist(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)    {
                    mat[i][j]=-1;
                    q.push({i,j,0});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto [x,y,dis]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 or nx>=n or ny<0 or ny>=m or mat[nx][ny]==-1)
                    continue;
                if(mat[nx][ny]==1){
                    mat[nx][ny]=-1;
                    q.push({nx,ny,dis+1});
                    dist[nx][ny]=dis+1;
                }
            }  
        }

        return dist;
    }
};