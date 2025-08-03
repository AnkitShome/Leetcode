class Solution {
public:

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        int n=intervals.size();
        int m=queries.size();
        for(int i=0;i<m;i++){
            mp[queries[i]].push_back(i);
        }
        sort(intervals.begin(),intervals.end());
        sort(queries.begin(),queries.end());
        for(auto i:intervals)   {for(auto j:i)   cout<<j<<" ";cout<<endl;}
        int i=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans(m);
        for(auto q:queries){
            while(i<n and intervals[i][0]<=q){
                int l=intervals[i][0],r=intervals[i][1];
                pq.push({r-l+1,r});
                i++;
            }
            while(!pq.empty() and pq.top().second<q){
                pq.pop();
            }
            for(auto x:mp[q]){
                pq.size()?ans[x]=pq.top().first:ans[x]=-1;
            }
        }
        return ans;
    }
};