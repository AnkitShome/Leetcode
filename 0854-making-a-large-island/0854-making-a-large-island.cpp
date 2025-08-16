class Solution {
public:

    class DSU {
    public:
        vector<int> parent, size;
        int n;

        DSU(int n) {
            this->n = n;
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findUpar(int node) {
            if (parent[node] == node) return node;
            return parent[node] = findUpar(parent[node]);
        }

        void unite(int a, int b) {
            a = findUpar(a);
            b = findUpar(b);
            if (a == b) return;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }

        bool samePar(int a, int b) {
            a = findUpar(a);
            b = findUpar(b);
            return a == b;
        }
    };

private:
    bool isValid(int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) return false;
        return true;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();   
        auto id = [&](int r, int c) {
            return r * m + c;
        };

        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        DSU dsu(n * m);

        vector<pair<int,int>> zero;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (!vis[x][y] && grid[x][y] == 1) {
                    vis[x][y]=1;
                    for(auto [dx,dy]:dirs){
                        int nx=x+dx;
                        int ny=y+dy;
                        if(!isValid(nx,ny,n,m) or grid[nx][ny]==0) continue;
                        dsu.unite(id(x,y),id(nx,ny));
                    }
                }
                if (grid[x][y] == 0) {
                    zero.push_back({x, y});
                }
            }
        }

        if(!zero.size())    return n*m;

        int ans=0;

        for(auto [x,y]:zero){
            unordered_set<int> st;
            for(auto [dx,dy]:dirs){
                int nx=x+dx;
                int ny=y+dy;
                if(!isValid(nx,ny,n,m)) continue;
                if(grid[nx][ny]==0) continue;
                int ult=dsu.findUpar(id(nx,ny));
                st.insert(ult);
            }
            int total=0;
            for(auto i:st){
                total+=dsu.size[i];
            }
            ans=max(ans,total+1);
        }
            
        return ans;
    }
};
