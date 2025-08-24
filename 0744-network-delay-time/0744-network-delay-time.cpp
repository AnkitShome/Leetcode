class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n,1e9);
        vector<vector<pair<int,int>>> adj(n);
        for(auto t:times){
            int u=t[0]-1;
            int v=t[1]-1;
            int d=t[2];
            adj[u].push_back({v,d});
        }


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        --k;
        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();

            for(auto [it,edw]:adj[node]){
                int xd=d+edw;
                if(dist[it]<=xd) continue;
                dist[it]=xd;
                pq.push({xd,it});
            }
        }
        int mint=0;
        for(int i=0;i<n;i++){
            if(i==k)    continue;
            if(dist[i]==1e9)    return -1;
            mint=max(mint,dist[i]);
        }
        return mint;    
    }
};
