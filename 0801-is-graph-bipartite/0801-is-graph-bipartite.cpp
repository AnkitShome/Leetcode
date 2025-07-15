class Solution {
public:

    bool dfs(int node,int col,vector<int> &color,vector<vector<int>> &adj){
        color[node]=col;
        for(auto it:adj[node]){
            if(color[it]==2){
                if(!dfs(it,col^1,color,adj))   return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,2);
        for(int i=0;i<n;i++){
            if(color[i]==2){
                if(!dfs(i,0,color,graph))   return false;
            }
        }
        return true;
    }
};