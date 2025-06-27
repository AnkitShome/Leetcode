class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> NSE(n,n),PSE(n,-1);

        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i])    st.pop();
            if(!st.empty()) PSE[i]=st.top();
            st.push(i);
        }

        while(!st.empty())  st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i])    st.pop();
            if(!st.empty()) NSE[i]=st.top();
            st.push(i);    
        }

        int area=0;

        for(int i=0;i<n;i++){
            int l=PSE[i];
            int r=NSE[i];
            int w=r-l-1;
            area=max(area,heights[i]*w);
        }

        return area;
    }
};