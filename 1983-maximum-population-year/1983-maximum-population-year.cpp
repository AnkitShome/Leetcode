class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        sort(logs.begin(),logs.end());
        vector<int> arr(101);
        int cur=0;
        int res=INT_MIN;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int b=logs[i][0];
            int d=logs[i][1];
            b-=1950;
            d-=1950;
            arr[b]++;
            arr[d]--;
        }
        for(int i=0;i<100;i++){
            cur+=arr[i];
            if(cur>res){
                res=cur;
                ans=1950+i;
            }
        }
        return ans;
    }
};