class Solution {

    class DSU{
        vector<int> parent,size;
        public:  
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++)    parent[i]=i;
        }

        int find(int node){
            if(parent[node]==node)  return node;
            return parent[node]=find(parent[node]);
        }

        void unite(int a,int b){
            a=find(a);
            b=find(b);
            if(a==b)    return;
            if(size[a]<size[b]) parent[a]=b;
            else if(size[a]>size[b])    parent[b]=a;
            else{
                size[a]++;
                parent[b]=a;
            }
        }

    };

public:

    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto i:edges){
            dsu.unite(i[0],i[1]);
        }

        map<int,int> group;

        for(int i=0;i<n;i++){
            group[dsu.find(i)]++;
        }

        if(group.size()<2)  return 0;

        long long ans=0;

        for(auto [_,count]:group){
            int rem=n-count;
            ans+=(1LL*rem*count);
        }
        return ans/2;
    }
};