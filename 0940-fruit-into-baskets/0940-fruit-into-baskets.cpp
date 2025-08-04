class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0,r=0;
        
        unordered_map<int,int> st;
        
        int ans=0;

        for(r=0;r<n;r++){
            st[fruits[r]]++;
            while(st.size()>2){
                st[fruits[l]]--;
                if(st[fruits[l]]==0)    st.erase(fruits[l]);
                l++;
            }
            int present=r-l+1;
            ans=max(ans,present);
        }
        return ans;
    }
};
