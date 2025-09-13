class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n=nums2.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j])  mp[i]=j;
            }
        }

        vector<int> NGE(n,-1);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums2[st.top()]<=nums2[i]){
                st.pop();
            }
            if(!st.empty()) NGE[i]=st.top();
            st.push(i);
        }

        // for(int i=0;i<n;i++){
        //     while(!st.empty() and nums2[st.top()]<nums2[i]){
        //         NGE[st.top()]=i;
        //         st.pop();
        //     }
        //     st.push(i);
        // }
        vector<int> ans;
        
        for(int i=0;i<nums1.size();i++){
            if(!mp.count(i))    {ans.push_back(-1);continue;}  
            if(NGE[mp[i]]!=-1)  
                ans.push_back(nums2[NGE[mp[i]]]);
            else    ans.push_back(-1);
        }
        return ans;
        
    }
};