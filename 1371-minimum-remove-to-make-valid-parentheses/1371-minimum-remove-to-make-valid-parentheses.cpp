class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        int n=s.size();
        vector<bool> luffy(n,0);
        for(int i=0;i<n;i++){
            if(s[i]>='a' and s[i]<='z'){
                luffy[i]=1;
                continue;
            }
            if(s[i]=='('){
                st.push({'(',i});
            }
            else{
                if(st.empty())  continue;
                auto [ch,j]=st.top();
                st.pop();
                luffy[i]=1;
                luffy[j]=1;
            }
        }
        string res="";
        for(int i=0;i<n;i++){
            if(luffy[i])    res+=s[i];
        }
        return res;
    }
};