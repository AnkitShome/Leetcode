class Solution {
public:
    int n;
    int dp[100001][3];

    int f(int i,int state,vector<int> &nums1,vector<int> &nums2){
        if(state==2 || i==n)    return 0;

        if(dp[i][state]!=-1)  return dp[i][state];

        int done=0,stick=0;
        if(state==0){
            stick=f(i+1,state,nums1,nums2);
            done=nums2[i]-nums1[i]+f(i+1,1,nums1,nums2);
        }
        else if(state==1){
            stick=nums2[i]-nums1[i]+f(i+1,state,nums1,nums2);
            done=f(i+1,2,nums1,nums2);
        }

        return dp[i][state]=max(stick,done);
    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        int s=0,t=0;
        for(int i=0;i<n;i++){
            s+=nums1[i];t+=nums2[i];
        }
        memset(dp,-1,sizeof(dp));
        int a=f(0,0,nums1,nums2);
        memset(dp,-1,sizeof(dp));
        int b=f(0,0,nums2,nums1);
        return max(s+a,t+b);
    }
};