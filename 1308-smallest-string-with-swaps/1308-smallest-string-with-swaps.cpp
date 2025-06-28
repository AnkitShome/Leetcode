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

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        DSU dsu(n);
        for(auto i:pairs){
            dsu.unite(i[0],i[1]);
        }

        map<int,set<int>> groups;
        for(int i=0;i<n;i++){
            int p=dsu.find(i);
            groups[p].insert(i);
        }

        vector<char> res(n);

        for(auto [node,ind]:groups){
            multiset<char> st;
            for(auto i:ind) st.insert(s[i]);

            auto it1 = ind.begin();
            auto it2 = st.begin();
            while (it1 != ind.end() && it2 != st.end()) {
                res[*it1] = *it2;
                ++it1;
                ++it2;
            }
        }

        string ans="";
        for(auto i:res) ans+=i;
        return ans;
    }
};