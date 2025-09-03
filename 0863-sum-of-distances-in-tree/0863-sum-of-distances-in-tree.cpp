class Solution {
public:
    vector<int> ans,sub,vis;
    int m;
    void dfs1(int node,vector<vector<int>>& adj){
        vis[node]=1;
        sub[node]=1;
        for(auto it:adj[node]){
            if(vis[it]) continue;
            dfs1(it,adj);
            sub[node]+=sub[it];
            ans[node]+=(ans[it]+sub[it]);
        }

    }

    void dfs2(int node,vector<vector<int>>& adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]) continue;
            ans[it]=ans[node]+(m-sub[it])-sub[it];
            dfs2(it,adj);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        m=n;
        ans.resize(n);
        sub.resize(n);    
        vis.assign(n,0);
        dfs1(0,adj);
        vis.assign(n,0);
        dfs2(0,adj);
        return ans;
    }

};