class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                if((nums[l]+nums[r])==(-nums[i])){
                    if(st.count({nums[i],nums[l],nums[r]})) {l++;continue;}
                    st.insert({nums[i],nums[l],nums[r]});
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                } 
                else if((nums[l]+nums[r])<(-nums[i])){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};