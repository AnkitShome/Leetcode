class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> NSE(n,n),PSE(n,-1);

        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and nums[st.top()]>=nums[i])    st.pop();
            if(!st.empty()) PSE[i]=st.top();
            st.push(i);
        }

        while(!st.empty())  st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums[st.top()]>=nums[i])    st.pop();
            if(!st.empty()) NSE[i]=st.top();
            st.push(i);    
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int x=NSE[i]-1;
            int y=PSE[i]+1;
            
            if(x>=k and y<=k){
                int w=x-y+1;
                int res=nums[i]*w;
                ans=max(ans,res);
            }
            
        }

        return ans;
    }
};