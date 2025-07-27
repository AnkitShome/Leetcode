class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int count=0;
        int k=0;
        while(i<n){
            int j=i+1;
            nums[k]=nums[i];
            k++;
            count++;
            while(j<n and nums[j]==nums[i]) j++;
            i=j;
        }
        return count;
    }
};