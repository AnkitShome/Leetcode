class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(i=='(' or i=='{' or i=='['){
                st.push(i);
            }
            else{

                if(st.empty())  return false;
                char last=st.top();
                if(i==')' and last=='(')    st.pop();
                else if(i=='}' and last=='{')    st.pop();
                else if(i==']' and last=='[')   st.pop();
                else return false;
            }
        }
        if(st.size())   return false;
        return true;
    }
};