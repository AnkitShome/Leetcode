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
    int n = grid.size(), m = grid[0].size();
    auto id = [&](int i, int j) { return i * m + j; };
    vector<pair<int,pair<int,int>>> cells;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cells.push_back({grid[i][j], {i, j}});
        }
    }

    sort(cells.begin(), cells.end());

    DSU dsu(n * m);
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<bool>> active(n, vector<bool>(m, false));

    for (auto &[h, cell] : cells) {
        auto [x, y] = cell;
        active[x][y] = true;
        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (active[nx][ny]) {
                dsu.unite(id(x,y), id(nx,ny));
            }
        }
        if (dsu.couple(id(0,0), id(n-1,m-1))) {
            return h; 
        }
    }
    return -1; 
}

};