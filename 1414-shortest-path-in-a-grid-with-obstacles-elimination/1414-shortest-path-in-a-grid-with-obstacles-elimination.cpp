class Solution {
public:
    const int INF=1e9;
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    int shortestPath(vector<vector<int>>& grid, int k) {
        n=grid.size(),m=grid[0].size();
        vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m,vector<bool>(k+1)));
        queue<tuple<int,int,int,int>> q;
        q.push({0,0,0,0});
        vis [0][0][0]=1;

        while(!q.empty()){
            auto [i,j,obs,moves]=q.front();
            q.pop();
            if(i==n-1 and j==m-1)   return moves;
            for(int r=0;r<4;r++){
                int x=i+dx[r];
                int y=j+dy[r];

                if(x<0 or x>=n or y<0 or y>=m or vis[x][y][obs])  continue;

                if(grid[x][y]==1){
                    if(obs==k)  continue;
                    vis[x][y][obs]=1;
                    q.push({x,y,obs+1,moves+1});
                }
                else{
                    vis[x][y][obs]=1;
                    q.push({x,y,obs,moves+1});
                }
            }
        }

        return -1;
    }
};