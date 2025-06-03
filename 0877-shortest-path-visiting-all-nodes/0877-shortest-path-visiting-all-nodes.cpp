class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int target=(1<<n)-1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            queue<tuple<int,int,int>> q;
            vector<vector<bool>> vis(n,vector<bool>(1<<n));

            q.push({i,(1<<i),0});  //i,mask,moves
            vis[i][(1<<i)]=1;

            while(!q.empty()){
                auto [node,mask,moves]=q.front();
                q.pop();
                if(mask==target)    {
                    cout<<i<<" "<<moves<<endl;
                    ans=min(ans,moves);break;}

                for(auto it:graph[node]){
                    int nmask=mask;
                    nmask=nmask | (1<<it);
                    if(vis[it][nmask])  continue;

                    vis[it][nmask]=1;
                    q.push({it,nmask,moves+1});
                }
            }
        }
        return ans;
    }
};