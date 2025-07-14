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
            if(a==b)    return;
            if(a<b) swap(a,b);
            parent[b]=a;
            if(size[a]==size[b])    size[a]++;
        }

    };

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        
        DSU dsu(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    dsu.unite(i,j);
                }
            }
        }
        int count=0;
        set<int> st;
        for(int i=0;i<n;i++){
            int par=dsu.find(i);
            if(!st.count(par)){
                st.insert(par);
                count++;
            }
        }
        return count;
    }
};