class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int last=nums[0];
        int count=1;
        for(int i=1;i<n;i++){
            if((nums[i]-last)>k){
                count++;
                last=nums[i];
            }
        }
        return count;
    }
};