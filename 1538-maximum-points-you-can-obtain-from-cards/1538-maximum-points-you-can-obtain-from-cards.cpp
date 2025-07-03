class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> prefix(n+1);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+cardPoints[i];
        }
        if(n==k)    return prefix[n];
        int rem=n-k;
        int right=rem;
        int left=0;
        int total=prefix[n];

        int ans=0;

        while(right<=n){
            int sum=prefix[right]-prefix[left];
            ans=max(ans,total-sum);
            right++;
            left++;
        }
        return ans;
    }
};