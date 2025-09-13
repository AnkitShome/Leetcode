class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int count=0;
        while(i<n){
            j=i+1;
            while(j<n and nums[i]==nums[j] and nums[i]==1){
                j++;
            }
            count=max(count,j-i);
            i=j;
        }
        return count;
    }
};