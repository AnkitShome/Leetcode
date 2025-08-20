class Solution {
public:
    string removeDuplicateLetters(string s) {
       string ans="";
        stack<char> st;
        unordered_map<char,int> count;
        for(auto i:s)   count[i]++;
        unordered_map<char,int> vis;
        for(auto i:s){
            count[i]--;
            if(vis[i])  continue;
            while(!st.empty() and i<st.top() and count[st.top()]>0){
                vis[st.top()]=0;
                st.pop();
            }
            st.push(i);
            vis[i]=1;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};