class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0)  {st.push(asteroids[i]);continue;}
            while(!st.empty() and st.top()>0 and abs(st.top())<abs(asteroids[i])){
                st.pop();
            }
            if(!st.empty() and abs(st.top())==abs(asteroids[i]) and st.top()>0){
                st.pop();continue;
            }
            if(!st.empty() and st.top()>0 and abs(st.top())>abs(asteroids[i]))    continue;
            st.push(asteroids[i]);
        }
        vector<int> ans;
        while(!st.empty())  {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};