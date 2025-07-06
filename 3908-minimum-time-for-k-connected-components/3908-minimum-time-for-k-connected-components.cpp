#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
// #define endl '\n'
#define pb push_back
#define ff first
#define ss second
const ll mod = 1e9 + 7, MX = 2e5 + 5; const ll INF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int dxk[8] = { +2, +1, -1, -2, -2, -1, +1, +2}, dyk[8] = { +1, +2, +2, +1, -1, -2, -2, -1};
constexpr ll pct(int x) {return __builtin_popcount(x);}
constexpr ll bits(int x) {return x == 0 ? 0 : 31 - __builtin_clz(x);}
void remDup(vector<int>&v) {sort(all(v)); v.erase(unique(all(v)), end(v));}
ll power(ll a, ll b, ll MOD){ll res = 1;while(b > 0){if(b & 1)res=(res*a)%MOD;a =(a*a) % MOD;b=b>>1LL;}return res % MOD;}

class DSU {
public:
    vector<int> size, parent;
    int components;

    DSU(int n) {
        size.assign(n, 1);
        parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    int find_parent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find_parent(parent[node]);  
    }

    bool is_in_same(int node_u, int node_v)
    {
         int parent_u = find_parent(node_u);
         int parent_v = find_parent(node_v);
         return parent_u == parent_v;   
    }

    void union_by_size(int node_u, int node_v) {
        int parent_u = find_parent(node_u);
        int parent_v = find_parent(node_v);
        
        if (parent_u == parent_v) return; 
        components--; 

        if (size[parent_u] > size[parent_v]) {
            size[parent_u] += size[parent_v];
            parent[parent_v] = parent_u;
        } else {
            size[parent_v] += size[parent_u];
            parent[parent_u] = parent_v;
        }
    }
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n) , Dsu(n);
        vector<pair<int,pair<int,int>>> edge;
        for(auto & Edge : edges)
        {
            int u = Edge[0] , v = Edge[1] , time = Edge[2];
            edge.pb({time,{u,v}});
            Dsu.union_by_size(u,v);
        }
        if(Dsu.components >= k) return 0;
        sort(all(edge),greater<pair<int,pair<int,int>>>());
        
        int ans = edge[0].ff;
        for(auto & Edge : edge)
        {
            if(dsu.components < k) break; 
            auto &[time , pair] = Edge;
            auto &[u , v] = pair;

            if(dsu.is_in_same(u,v)) continue;
            dsu.union_by_size(u,v);
            ans = time;
        }
        return ans;
    }
};