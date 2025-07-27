class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n-1;
        long long res=0;
        while(i<j){
            j--;
            res+=nums[j];
            j--;
            i++;
        }
        return res;
    }
};