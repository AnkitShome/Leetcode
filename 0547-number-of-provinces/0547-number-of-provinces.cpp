class Solution {
public:

    class DSU{
        vector<int> parent,size;
        public:
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++)   parent[i]=i;
        }

        int find(int u){
            if(parent[u]==u)    return u;
            return parent[u]=find(parent[u]);
        }

        void unite(int a,int b){
            int pa=find(a);
            int pb=find(b);
            if(pa==pb)    return;
            if(size[pa]<size[pb]) swap(pa,pb);
            parent[pb]=pa;
            size[pa]++;
        }

    };

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        
        DSU dsu(n);
        
        int count=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 and dsu.find(i)!=dsu.find(j)){
                    dsu.unite(i,j);
                    count--;
                }
            }
        }
        return count;
    }
};