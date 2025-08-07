class Solution {
public:
    
    int dx[8]={1,1,-1,-1,0,0,-1,1};
    int dy[8]={1,-1,1,-1,1,-1,0,0};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)   return -1;
        vector<vector<int>> vis(n,vector<int>(n));
        queue<tuple<int,int,int>> q;
        q.push({0,0,1});
        vis[0][0]=1;

        while(!q.empty()){
            auto [x,y,d]=q.front();
            q.pop();
            if(x==n-1 and y==n-1)    return d;
            for(int k=0;k<8;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 or ny<0 or nx>=n or ny>=n or vis[nx][ny] or grid[nx][ny]==1)   continue;
                vis[nx][ny]=1;
                q.push({nx,ny,d+1});
            }
        }
        return -1;
    }
};