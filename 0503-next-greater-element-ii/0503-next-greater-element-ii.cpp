class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> a;
        for(auto i:nums)    a.push_back(i);
        for(auto i:nums)    a.push_back(i);

        stack<int> st;
        int n=nums.size();
        vector<int> NGE(2*n,-1);

        for(int i=0;i<2*n;i++){
            while(!st.empty() and a[i]>a[st.top()]){
                NGE[st.top()]=a[i];
                st.pop();
            }
            st.push(i);
        }

        vector<int> ans(NGE.begin(),NGE.begin()+n);
        return ans;
    }
};