class Solution {
public:
    
    int count=0;

    long long dfs(int u,int par,vector<int> adj[],vector<int> &cost){
        if(adj[u].size()==1 and par!=-1)    return cost[u];

        vector<long long> paths;
        
        long long maxi=0;
        for(auto v:adj[u]){
            if(v==par)  continue;
            long long child=dfs(v,u,adj,cost);
            maxi=max(maxi,child);
            paths.push_back(child);
        }    

        for(auto i:paths){
            if(i<maxi)  count++;
        }

        return cost[u]+maxi;
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<int> adj[n];

        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        dfs(0,-1,adj,cost);
        return count;
    }
};