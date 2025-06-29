class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        deque<int> q;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<k;i++){
            q.push_back(nums[i]);
            st.insert(nums[i]);
        }
        ans.push_back(*st.rbegin());

        int i=k;
        while(i<n){
            q.push_back(nums[i]);
            int remove=q.front();
            q.pop_front();
            st.erase(st.find(remove));
            st.insert(nums[i]);
            ans.push_back(*st.rbegin());
            i++;
        }

        return ans;
    }
};