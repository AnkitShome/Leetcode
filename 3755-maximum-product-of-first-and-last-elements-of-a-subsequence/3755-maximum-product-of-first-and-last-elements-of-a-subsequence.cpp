class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        vector<int> maxP(n,INT_MIN);
        vector<int> maxN(n,INT_MAX);
        int neg=INT_MAX,pos=INT_MIN;
        for(int i=n-1;i>=0;i--){
            neg=min(neg,nums[i]);
            pos=max(pos,nums[i]);
            maxP[i]=pos;
            maxN[i]=neg;
        }

        long long maxi=LLONG_MIN;

        for(int i=0;i<n;i++){
            int j=i+m-1;
            if(j>=n)    continue;
            long long retsu=nums[i];
            if(retsu>0) retsu*=maxP[j];
            else    retsu*=maxN[j];
            maxi=max(maxi,retsu);
        }

        // cout<<maxi<<endl;

        // for(int i=0;i<n;i++){
        //     cout<<maxP[i]<<" "<<maxN[i]<<endl;
        // }
        return maxi;
    }
};