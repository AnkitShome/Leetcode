class Solution {
public:
    int dp[501];

    int f(int ind,vector<int> &arr,int k){
        int n=arr.size();
        if(ind==n)  return 0;
        if(dp[ind]!=-1) return dp[ind];
        int sum=0;
        int maxi=arr[ind];
        for(int m=0;m<k;m++){
            if(ind+m<n){
                maxi=max(maxi,arr[ind+m]);
                sum=max(sum,maxi*(m+1)+f(m+1+ind,arr,k));
            }
        }
        return dp[ind]=sum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,arr,k);
    }
};