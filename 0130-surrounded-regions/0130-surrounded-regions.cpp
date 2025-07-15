class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')    {q.push({i,0});vis[i][0]=1;}
            if(board[i][m-1]=='O')    {q.push({i,m-1});vis[i][m-1]=1;}
        }      
        for(int j=1;j<m-1;j++){
            if(board[0][j]=='O')    {q.push({0,j});vis[0][j]=1;}
            if(board[n-1][j]=='O')  {q.push({n-1,j});vis[n-1][j]=1;}
        }
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 or ny<0 or nx>=n or ny>=m or board[nx][ny]=='X' or vis[nx][ny]) continue;
                q.push({nx,ny});
                vis[nx][ny]=1;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};