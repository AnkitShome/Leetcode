class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto p:prerequisites){
            int u=p[0];
            int v=p[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)  q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it); 
            }
        }
        if(res.size()!=n)   return {};
        return res;
    }
};