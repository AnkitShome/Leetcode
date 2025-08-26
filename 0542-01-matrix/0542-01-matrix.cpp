class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
        queue<array<int,3>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({0,i,j});
                    dist[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            auto [d,x,y]=q.front();
            q.pop();

            for(auto [dx,dy]:dirs){
                int nx=x+dx;
                int ny=y+dy;
                if(min(nx,ny)<0 or nx>=n or ny>=m)  continue;
                if(mat[nx][ny]==0) continue;
                if(dist[nx][ny]<=d+1)   continue;
                dist[nx][ny]=d+1;
                q.push({d+1,nx,ny});
            }   
        }

        return dist;
        
    }
};