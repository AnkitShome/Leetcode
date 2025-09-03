class Solution {
public:

    vector<string> ans;
    void dfs(string node,unordered_map<string,multiset<string>>& adj){

        while(!adj[node].empty()){
            string child=*adj[node].begin();
            adj[node].erase(adj[node].find(child));
            dfs(child,adj);
        }

        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj;
        for(auto t:tickets){
            adj[t[0]].insert(t[1]);
        }
        dfs("JFK",adj);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};