class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        set<int> st;
        for(int i=0;i<n;i++){
           if(nums[i]==key) st.insert(i);
        }
        set<int> dist;
        for(int i=0;i<n;i++){
            for(auto j:st){
                if(abs(i-j)<=k) dist.insert(i);
            }
        }

        vector<int> ans(dist.begin(),dist.end());
        return ans;
    }
};