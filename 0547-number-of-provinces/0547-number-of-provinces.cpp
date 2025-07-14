class Solution {
public:
    vector<int> adj[200];
    int vis[200];
    int count=0;
    void dfs(int node){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]) continue;
            dfs(it);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                count++;
            } 
        }
        return count;
    }
};