
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e:flights){
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<vector<int>> dist(n,vector<int>(k+2,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        dist[src][0]=0;

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second.first;
            int c=pq.top().second.second;
            if(node==dst)   return d;
            pq.pop();
            if(c>k) continue;
            for(auto [child,w]:adj[node]){
                int wd=d+w;
                if(dist[child][c+1]>wd){
                    dist[child][c+1]=wd;
                    pq.push({wd,{child,c+1}});
                }
            }
        }
        return -1;
    }
};