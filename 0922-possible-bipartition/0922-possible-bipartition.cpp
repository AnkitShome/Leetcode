class Solution {
public:

    bool bip(int node,int col,vector<int>& color,vector<vector<int>>& adj){
        color[node]=col;
        for(auto it:adj[node]){
            if(color[it]==-1)   {if(!bip(it,!col,color,adj)) return false;}
            else if(color[it]==col) return false;
            else continue;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for(auto e:dislikes){
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]!=-1)  continue;
            if(!bip(i,0,color,adj))  return false;
        }
        return true;
    }
};