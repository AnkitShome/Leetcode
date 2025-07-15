class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        queue<pair<int,int>> q;
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)   total++;
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 and !vis[i][0])    {q.push({i,0});vis[i][0]=1;}
            if(grid[i][m-1]==1 and !vis[i][m-1])    {q.push({i,m-1});vis[i][m-1]=1;}
        }      
        for(int j=1;j<m-1;j++){
            if(grid[0][j]==1 and !vis[0][j])    {q.push({0,j});vis[0][j]=1;}
            if(grid[n-1][j]==1 and !vis[n-1][j])  {q.push({n-1,j});vis[n-1][j]=1;}
        }
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            total--;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 or ny<0 or nx>=n or ny>=m or vis[nx][ny] or grid[nx][ny]==0)    continue;
                q.push({nx,ny});
                vis[nx][ny]=1;
            }
        }
        return total;
    }
};