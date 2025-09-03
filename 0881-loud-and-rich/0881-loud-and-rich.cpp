class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        for(auto e:richer){
            adj[e[1]].push_back(e[0]);
        }

        vector<int> ans(n);

        for(int i=0;i<n;i++){
            queue<int> q;
            vector<int> vis(n);
            vis[i]=1;
            q.push(i);
            int res=i;
            int level=quiet[i];
            while(!q.empty()){
                int node=q.front();
                if(quiet[node]<level){
                    level=quiet[node];
                    res=node;
                }
                q.pop();

                for(auto it:adj[node]){
                    if(vis[it]) continue;
                    q.push(it);
                    vis[it]=1;
                }
            }
            ans[i]=res;
        }
        return ans;
    }
};