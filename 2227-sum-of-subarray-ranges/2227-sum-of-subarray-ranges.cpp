class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        int lg[n+1];
        lg[1]=0;
        for(int i=2;i<=n;i++)   lg[i]=lg[i/2]+1;

        int k=lg[n];

        int st_max[k+1][n];
        int st_min[k+1][n];

        copy(nums.begin(),nums.end(),st_min[0]);
        copy(nums.begin(),nums.end(),st_max[0]);

        for(int i=1;i<=k;i++)
            for(int j=0;j+(1<<i)<=n;j++)
                st_min[i][j]=min(st_min[i-1][j],st_min[i-1][j+(1<<(i-1))]);
                
        for(int i=1;i<=k;i++)
            for(int j=0;j+(1<<i)<=n;j++)
                st_max[i][j]=max(st_max[i-1][j],st_max[i-1][j+(1<<(i-1))]);

        long long sum=0;
        for(int L=0;L<n;L++){
            for(int R=L;R<n;R++){
                int i=R-L+1;
                int j=lg[i];
                int mini=min(st_min[j][L],st_min[j][R-(1<<j)+1]);
                int maxi=max(st_max[j][L],st_max[j][R-(1<<j)+1]);
                sum+=(maxi-mini);
            }
        }

        return sum;
    }
};