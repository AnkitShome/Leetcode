class Solution {
public:

    class DSU{
        int n;
        vector<int> parent,size;

        public:
        DSU(int n):n(n){
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++){
                size[i]=1;
                parent[i]=i;
            }
        }

        int find_par(int node){
            if(node==parent[node])  return node;
            return parent[node]=find_par(parent[node]);
        }

        void unite(int a,int b){
            a=find_par(a);
            b=find_par(b);
            if(a==b)    return;
            if(size[a]<size[b]) swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
        }

        bool couple(int a,int b){
            a=find_par(a);
            b=find_par(b);
            if(a==b)    return true;
            return false;
        }
    };

    bool isValid(int x,int y,int n,int m){
        if(min(x,y)<0 or x>=n or y>=m)  return false;
        return true;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
        
        int max_time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int height=grid[i][j];
                adj[height].push_back({i,j});
                max_time=max(max_time,height);
            }
        }

        auto id=[&](int i,int j){
            return i*m+j;
        };

        DSU dsu(n*m);

        int time=0;
        while(time<max_time){
            if(adj.find(time)==adj.end()){time++;continue;}
            for(auto [x,y]:adj[time]){
                for(auto [dx,dy]:dirs){
                    int nx=x+dx;
                    int ny=y+dy;
                    if(!isValid(nx,ny,n,m)) continue;
                    if(grid[nx][ny]>time)   continue;
                    dsu.unite(id(x,y),id(nx,ny));
                }
            }
            if(dsu.couple(id(0,0),id(n-1,m-1))) return time;
            time++;
        }

        return max_time;
    }
};