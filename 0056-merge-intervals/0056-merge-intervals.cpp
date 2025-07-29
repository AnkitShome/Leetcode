class Solution {
public:
    static bool compare(const vector<int> &a,const vector<int> &b){
        if(a[0]==b[0])  return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        for(auto i:intervals)   cout<<i[0]<<" "<<i[1]<<endl;
        vector<vector<int>> ans;
        int n=intervals.size();
        int m=intervals[0][0];
        int M=intervals[0][1];
        int i=1;
        while(i<n){
            if(M>=intervals[i][0]){
                m=min(m,intervals[i-1][0]);
                M=max(M,intervals[i][1]);
            }
            else{
                ans.push_back({m,M});
                m=intervals[i][0];
                M=intervals[i][1];
            }
            i++;
        }       
        ans.push_back({m,M});
        return ans; 
    }
};
