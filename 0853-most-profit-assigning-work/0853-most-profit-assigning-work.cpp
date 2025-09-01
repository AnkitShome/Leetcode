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

        int ans=0;
        sort(worker.begin(),worker.end());

        int j=0;
        int best=0;
        for(int i=0;i<n;i++){
            while(j<m and worker[i]>=rv[j].first){
                best=max(best,rv[j].second);
                j++;
            }
            ans+=best;
        }
        return ans;
    }
};