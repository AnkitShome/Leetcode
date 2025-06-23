class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n=nums2.size();
        vector<int> NGE(n,-1);
       
        unordered_map<int,int> mp;
        for(auto i:nums1){
            for(int j=0;j<n;j++){
                if(nums2[j]==i) mp[i]=j;
            }
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums2[st.top()]<=nums2[i]){
                st.pop();
            }
            if(!st.empty()) NGE[i]=st.top();
            st.push(i);
        }

        for(auto i:NGE) cout<<i<<" ";cout<<endl;

        vector<int> ans;
        for(auto i:nums1){
            if(NGE[mp[i]]==-1)   ans.push_back(-1);
            else    ans.push_back(nums2[NGE[mp[i]]]);
        }
        return ans;
    }
};