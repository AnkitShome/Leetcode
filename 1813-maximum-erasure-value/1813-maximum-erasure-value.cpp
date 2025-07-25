class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n+1);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i];
            pre[i+1]+=nums[i];
        }
        int i=0,j=0;
        set<int> st;
        unordered_map<int,int> mp;
        int res=0;
        while(j<n and i<=j){
            while(st.count(nums[j])){
                st.erase(nums[i]);
                i++;
            }
            st.insert(nums[j]);
            int raze=pre[j+1]-pre[i];
            res=max(res,raze);
            j++;
        }
        return res;
    }
};