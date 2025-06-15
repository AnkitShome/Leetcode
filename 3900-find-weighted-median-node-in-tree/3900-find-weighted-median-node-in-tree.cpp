class Solution {
public:

    const int N=1e5;
    vector<int> level;
    vector<vector<pair<int,int>>> adj;
    vector<long long> dist;
    vector<vector<int>> par;

    void dfs(int node,int parent,int l=0,long long newD=0){
        par[node][0]=parent;
        level[node]=l;
        dist[node]=newD;
        for(int i=1;i<17;i++){
            if(par[node][i-1]==-1)  continue;
            par[node][i]=par[par[node][i-1]][i-1];
        }
        for(auto [v,w]:adj[node]){
            if(v==parent)   continue;
            dfs(v,node,l+1,newD+w);
        }
    }

    int getKpar(int node,int k){
        for(int i=0;i<17;i++){
            if(k&(1<<i)){
                if(par[node][i]==-1)    break;
                node=par[node][i];
            }
        }
        return node;
    }

    int lca(int a,int b){
        if(level[a]<level[b])   swap(a,b);
        int k=level[a]-level[b];
        a=getKpar(a,k);
        if(a==b)    return a;
        for(int i=16;i>=0;i--){
            if(par[a][i]==par[b][i])    continue;
            a=par[a][i];
            b=par[b][i];
        }
        return par[a][0];
    }

    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        par.resize(n,vector<int>(17,-1));
        dist.resize(n,INT_MAX);
        level.resize(n);
        adj.resize(n);

        for(int i=0;i<n-1;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int d=edges[i][2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        dfs(0,-1,0);

        vector<int> ans;
        for(auto q:queries){
            int u=q[0];
            int v=q[1];
            int x=lca(u,v);
            long long d_uv=dist[u]+dist[v]-2*dist[x];

            long long d_xu=dist[u]-dist[x];
            long long d_xv=dist[v]-dist[x];

            long long mid=(d_uv+1)/2;

            if(d_xu>=mid){
                int node=u;
                long long rem=mid;
                for(int i=16;i>=0;i--){
                    if(par[node][i]==-1)    continue;
                    int anc=par[node][i];
                    long long ed=dist[node]-dist[anc];
                    if(ed<=rem)  {node=anc;rem-=ed;}
                }
                rem==0?ans.push_back(node):ans.push_back(par[node][0]);
            }

            else{
                long long climbFromLCA=mid-d_xu;
                long long rem=d_xv-climbFromLCA;
                int node=v;
                for(int i=16;i>=0;i--){
                    int anc=par[node][i];
                    if(anc==-1) continue;
                    long long ed=dist[node]-dist[anc];
                    if(ed<=rem){rem-=ed;node=anc;}
                }
                ans.push_back(node);
            }
        }
        return ans;
    }
};