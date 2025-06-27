class Solution {
public:

    class DSU{
        vector<int> parent,size;

        
        public:

        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++)    parent[i]=i;
        }

        int findUpar(int node){
            if(node==parent[node])  return node;
            return parent[node]=findUpar(parent[node]);
        }

        void connect(int u,int v){
            int pu=findUpar(u);
            int pv=findUpar(v);
            if(pu==pv)  return;
            if(size[pu]>size[pv]){
                parent[pv]=pu;
            }
            else if(size[pu]<size[pv]){
                parent[pu]=pv;
            }
            else{
                parent[pu]=pv;
                size[pv]++;
            }
        }
    };

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<vector<int>> adj(n);
        map<int,vector<int>> mp;
        
        int ans=n;

        for(auto i:edges){
            if(vals[i[0]]>=vals[i[1]])
                adj[i[0]].push_back(i[1]);
            if(vals[i[1]]>=vals[i[0]])
                adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            mp[vals[i]].push_back(i);
        }

        DSU dsu(n);

        for(auto [val,nodes]:mp){
            for(auto node:nodes){
                for(auto it:adj[node]){
                    dsu.connect(node,it);
                }
            }

            unordered_map<int,int> groups;

            for(auto node:nodes){
                groups[dsu.findUpar(node)]++;
            }

            int cnt=0;

            for(auto [uPar,total]:groups){
                cnt+=(total*(total-1))/2;
            }

            ans+=cnt;
        }
        
    return ans;
    }
};