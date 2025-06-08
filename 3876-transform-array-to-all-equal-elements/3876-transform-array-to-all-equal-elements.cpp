class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        vector<int> a(nums);
        int i=0;
        int op=0;
        while(i<n-1){
            if(nums[i]==1) i++;
            else if(nums[i]==-1){
                nums[i]*=-1;
                nums[i+1]*=-1;
                op++;
                i++;
            }
        }
        bool bias=1;
        for(auto i:nums){
            if(i!=1) bias=0;
        }
        int j=0;
        int ok=0;
        nums=a;
        while(j<n-1){
            if(nums[j]==-1) j++;
            else if(nums[j]==1){
                nums[j]*=-1;
                nums[j+1]*=-1;
                ok++;
                j++;
            }
        }
        bool ryan=1;
        for(auto i:nums){
            if(i!=-1) ryan=0;
        }
        if(op<=k and bias) {return true;}
        if(ok<=k and ryan){return true;}
        return false;
    }
};