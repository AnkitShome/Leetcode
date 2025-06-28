class Solution {
    
    class DSU{
        vector<int> parent,size;

        public:

        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++)    parent[i]=i;
        }

        int find(int x){
            if(parent[x]!=x)    parent[x]=find(parent[x]);
            return parent[x];
        }

        void unite(int u,int v){
            int a=find(u);
            int b=find(v);
            if(a==b)    return;
            if(size[a]>size[b]){
                parent[b]=a;
            }
            else if(size[a]<size[b]){
                parent[a]=b;
            }
            else{
                parent[b]=a;
                size[a]++;
            }
        }
    };

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        map<string,int> name;
        map<int,int> holder;

        int n=accounts.size();

        DSU dsu(n);

        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(name.find(accounts[i][j])==name.end())
                    name[accounts[i][j]]=i;
                else{
                    dsu.unite(name[accounts[i][j]],i);
                }
            }
        }

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int p=dsu.find(i);
            holder[i]=p;
            mp[i]=p;
        }   
        
        map<int,set<string>> res;
  
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                res[holder[i]].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> ans;

        for(auto [ind,emails]:res){
            vector<string> row;
            row.push_back(accounts[ind][0]);
            for(auto email:emails)  row.push_back(email);
            ans.push_back(row);
        }

        return ans;
    }
};