class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums;
        int i=0,j=0;
        swap(n,m);
        while(i<n and j<m){
            int a=nums1[i];
            int b=nums2[j];
            if(a<=b){
                nums.push_back(a);
                i++;
            }
            else{
                nums.push_back(b);
                j++;
            }
        }
        while(i<n)  {nums.push_back(nums1[i]);i++;}
        while(j<m)  {nums.push_back(nums2[j]);j++;}
        for(int i=0;i<n+m;i++){
            nums1[i]=nums[i];
        }
    }
};