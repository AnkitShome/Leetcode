class Solution {
public:
    class DSU{
        public:
        vector<int> parent;
        vector<set<int>> groups;
        
        DSU(int n):parent(n+1),groups(n+1){
            for(int i=1;i<=n;i++)   {parent[i]=i;groups[i].insert(i);}
        }

        int find(int x){
            if(parent[x]==x)    return x;
            return parent[x]=find(parent[x]);
        }

        void unite(int a,int b){
            a=find(a);
            b=find(b);
            if(a==b)    return;
            if(groups[a].size()<groups[b].size()){
                swap(a,b);
            }
            for(auto i:groups[b]){
                groups[a].insert(i);
            }
            groups[b].clear();
            parent[b]=a;
        }
    };
 
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        int n=c;
        DSU dsu(n);
        
        for(auto i:connections){
            dsu.unite(i[0],i[1]);
        }

        int q=queries.size();
        vector<int> vis(n+1,1);

        vector<int> ans;

        for(auto x:queries){
            int j=x[0];
            int node=x[1];

            if(j==1){
                int par=dsu.find(node);
                bool found=0;
                if(vis[node])   {ans.push_back(node);continue;}
                if(dsu.groups[par].empty()) ans.push_back(-1);
                else ans.push_back(*dsu.groups[par].begin());
            }
            else{
                vis[node]=0;
                int par=dsu.find(node);
                dsu.groups[par].erase(node);
            }
        }

        return ans;
    }
};