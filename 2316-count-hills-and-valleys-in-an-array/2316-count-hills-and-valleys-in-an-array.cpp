class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> a;

        int i=0;
        while(i<nums.size()){
            a.push_back(nums[i]);
            int j=i+1;
            while(j<nums.size() and nums[j]==nums[i]) j++;
            i=j;
        }

        int count=0;
        for(int i=1;i<a.size()-1;i++){
            if(( (a[i]<a[i-1]) and (a[i]<a[i+1]) ) or ( (a[i]>a[i-1]) and (a[i]>a[i+1] )))
                count++;
        }
        return count;
    }
};