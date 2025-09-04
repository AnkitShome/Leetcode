class Solution {
public:
   

    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
        return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
    });
        
        int ans=0;

        for(int i=0;i<n;i++){
            int maxm=INT_MIN;
            for(int j=i+1;j<n;j++){
                if(points[i][1]>=points[j][1] and points[j][1]>maxm){
                    ans++;
                    maxm=points[j][1];
                }
            }
        }

        return ans;

    }
};