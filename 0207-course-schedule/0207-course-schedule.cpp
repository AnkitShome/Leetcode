class Solution {
public:

    bool dfs(int node,vector<int> &vis,vector<vector<int>>&adj,vector<int> &recstack){
        vis[node]=1;
        recstack[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj,recstack))    return true;
            }
            else if(recstack[it]){
                return true;
            }
        }
        recstack[node]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto j:prerequisites){
            int u=j[0];
            int v=j[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        vector<int> recstack(n);
        vector<int> vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]) if(dfs(i,vis,adj,recstack)) return false;
        }
        return true;

        // queue<int> q;
        // for(int i=0;i<n;i++){
        //     if(indegree[i]==0)  {q.push(i);vis[i]=1;}
        // }

        // vector<int> topo;
        // while(!q.empty()){
        //     auto u=q.front();q.pop();
        //     topo.push_back(u);
        //     for(auto v:adj[u]){
        //         if(vis[v])  continue;
        //         indegree[v]--;
        //         if(!indegree[v]){
        //             q.push(v);
        //             vis[v]=1;
        //         }
        //     }
        // }
        // if(topo.size()==n)  return true;
        // return false;
    }
};