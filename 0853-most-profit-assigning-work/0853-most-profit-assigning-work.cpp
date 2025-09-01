class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=worker.size();
        int m=difficulty.size();
        vector<pair<int,int>> rv(m);
        for(int i=0;i<m;i++){
            rv[i]={difficulty[i],profit[i]};
        }
        sort(difficulty.begin(),difficulty.end());
        sort(rv.begin(),rv.end());

        vector<int> prefix(m+1);
        for(int i=1;i<=m;i++){
            prefix[i]=max(prefix[i-1],rv[i-1].second);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int it=upper_bound(difficulty.begin(),difficulty.end(),worker[i])-difficulty.begin();
            it--;
            if(it<0)    continue;
            ans+=prefix[it+1];
        }
        return ans;
    }
};