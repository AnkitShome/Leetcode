class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> bits(32);
        vector<int> res(n);
        vector<int> ans(n,1);
        for(int i=n-1;i>=0;i--){
            if(i<n-1)   res[i]=res[i+1];
            res[i]|=nums[i];

            for(int b=0;b<32;b++){
                if((nums[i]&(1<<b)))
                    bits[b]=i;
            }
            int bit=res[i];
            int maxi=1;
            for(int b=0;b<32;b++){
                if((bit&(1<<b))){
                    maxi=max(maxi,bits[b]-i+1);
                }
            }
            ans[i]=maxi;
        }   
        return ans;
    }
};