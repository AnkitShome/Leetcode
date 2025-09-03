class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1)    {q.push(i);}
        }
        
        vector<int> ans;

        int rem=n;
        while(rem>2){
            int node=q.front();
            int sz=q.size();

            for(int i=0;i<sz;i++){
                int node=q.front();
                rem--;
                q.pop();
                for(auto it:adj[node]){
                    degree[it]--;
                    if(degree[it]==1){
                        q.push(it);
                    }
                }
            }

        }

        while(!q.empty())   {ans.push_back(q.front());q.pop();}
        if(!ans.size()) ans.push_back(0);
        return ans;
    }
};