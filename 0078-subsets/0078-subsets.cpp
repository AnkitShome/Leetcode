class Solution {
public:
    vector<vector<int>> ans;
    void f(int ind,vector<int>& res,vector<int>& nums){
        if(ind==nums.size()){
            ans.push_back(res);
            return;
        }    
        f(ind+1,res,nums);
        res.push_back(nums[ind]);
        f(ind+1,res,nums);
        res.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        f(0,res,nums);
        return ans;
    }
};