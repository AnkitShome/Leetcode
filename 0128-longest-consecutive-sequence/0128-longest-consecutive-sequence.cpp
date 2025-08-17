class Solution {
public:
    class DSU{
        public:
        unordered_map<int,int> parent,size;
        
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

        void add(int a){
            if(!parent.count(a)){
                parent[a]=a;
                size[a]=1;
            }
        }
        
    };
    
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        
        DSU dsu;
        
        for(auto x:s){
            dsu.add(x);
            if(dsu.parent.count(x+1)){
                dsu.unite(x,x+1);
            }
            if(dsu.parent.count(x-1)){
                dsu.unite(x,x-1);
            }
        }

        int ans=0;

        for(auto i:s){
            ans=max(ans,dsu.size[dsu.findPar(i)]);
        }

        return ans;
    }
};