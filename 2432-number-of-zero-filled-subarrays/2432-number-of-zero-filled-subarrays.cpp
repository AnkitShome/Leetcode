class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        int i=0;
        long long count=0;
        while(i<n){
            if(nums[i]==0){
                count++;
            }
            else{
                sum+=(count*(count+1))/2;
                count=0;
            }
            i++;
        }
        sum+=(count*(count+1))/2;
        return sum;
    }
};