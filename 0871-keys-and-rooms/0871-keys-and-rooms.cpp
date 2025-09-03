class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int total=0;
        queue<int> q;
        vector<int> vis(n);
        q.push(0);
        vis[0]=1;

        while(!q.empty()){
            int node=q.front();
            total++;
            q.pop();
            for(auto it:rooms[node]){
                if(vis[it]) continue;
                vis[it]=1;
                q.push(it);
            }
        }

        if(total==n)    return true;
        return false;
    }
};