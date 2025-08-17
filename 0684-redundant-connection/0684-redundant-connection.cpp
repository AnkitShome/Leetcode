class Solution {
public:
    class DSU{
        public:
        int n;
        vector<int> parent,size;
        
        DSU(int n):n(n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        
        int findPar(int node){
            if(node==parent[node])  return node;
            return parent[node]=findPar(parent[node]);
        }
        
        void unite(int a,int b){
            a=findPar(a);
            b=findPar(b);
            if(a==b)    return;
            if(size[a]<size[b]) swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
        }
        
        bool same(int a,int b){
            a=findPar(a);
            b=findPar(b);
            if(a==b)    return true;
            return false;
        }
    };
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n+1);
        for(auto e:edges){
            int x=e[0],y=e[1];
            if(dsu.same(x,y))   return {x,y};
            dsu.unite(x,y);
        }
        return {};
    }
};