class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX;
        vector<int> ls(landStartTime),ld(landDuration),ws(waterStartTime),wd(waterDuration);
        int n=landStartTime.size();
        int m=waterStartTime.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int r=ls[i]+ld[i];
                int x=INT_MAX;
                if(r<=ws[j]){
                    x=ws[j]+wd[j];
                }
                else{
                    x=r+wd[j];
                }
                ans=min(ans,x);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r=ws[i]+wd[i];
                int x=INT_MAX;
                if(r<=ls[j]){
                    x=ls[j]+ld[j];
                }
                else{
                    x=r+ld[j];
                }
                ans=min(ans,x);
            }
        }
        return ans;
    }
};



// 2 8
// 4 1

// 6
// 3


// 2,6 8,9

// 6,9
