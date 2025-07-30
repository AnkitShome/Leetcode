class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n),suf(n);
        pre[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                pre[i]=pre[i-1]+1;
            }  
            else    pre[i]=1;
        }
        suf[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                suf[i]=suf[i+1]+1;
            }
            else    suf[i]=1;
        }
        vector<int> ans;
        for(int i=1;i<n-1;i++){
            if(pre[i-1]>=k and suf[i+1]>=k) ans.push_back(i);
        }
        return ans;
    }
};