class Solution {
public:
    vector<int> vis;
    vector<vector<int>> adj;
    vector<vector<int>> ans;
    vector<int> in,out;
    int n;
    int time=0;

    void dfs(int node,vector<int> &subXor,vector<int> &nums){
        vis[node]=1;
        in[node]=++time;
        subXor[node]=nums[node];
        for(auto it:adj[node]){
            if(vis[it]) continue;
            dfs(it,subXor,nums);
            subXor[node]^=subXor[it];
        }
        out[node]=++time;
    }

    bool isDes(int u,int v){
        if((in[u]<in[v]) and (out[v]<out[u]))   return true;
        return false;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n=nums.size();
        adj.resize(n);
        vis.resize(n);
        in.resize(n);
        out.resize(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> subXor(n,0);
        dfs(0,subXor,nums);
        int ans=INT_MAX;
        
        for(int i=0;i<edges.size();i++){
            for(int j=i+1;j<edges.size();j++){
                
                int a=edges[i][0],b=edges[i][1];
                if(in[a]<in[b]) swap(a,b);
                int u=a;
                
                int c=edges[j][0],d=edges[j][1];
                if(in[c]<in[d])    swap(c,d);
                int v=c;

                int comp1=subXor[0];
                int comp2=-1;
                int comp3=-1;
                if(isDes(u,v)){
                    comp1=comp1^subXor[u];
                    comp2=subXor[u]^subXor[v];
                    comp3=subXor[v];
                }
                else if(isDes(v,u)){
                    comp1=comp1^subXor[v];
                    comp2=subXor[v]^subXor[u];
                    comp3=subXor[u];
                }
                else{
                    comp1=comp1^subXor[u]^subXor[v];
                    comp2=subXor[u];
                    comp3=subXor[v];
                }

                int res=max({comp1,comp2,comp3})-min({comp1,comp2,comp3});
                ans=min(ans,res);
            }
        }
        return ans;
    }
};