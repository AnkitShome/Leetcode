class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int eva=0;
        queue<array<int,3>> q;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)   eva++;
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }

        int ans=0;

        while(!q.empty()){
            auto [x,y,time]=q.front();
            ans=max(ans,time);
            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 or nx>=n or ny<0 or ny>=m or grid[nx][ny]!=1)
                    continue;
                
                grid[nx][ny]=2;
                eva--;
                q.push({nx,ny,time+1});
            }
        }
        if(eva) return -1;
        return ans;
    }
};