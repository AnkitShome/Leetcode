class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0,r=0;
        
        map<int,int> st;
        
        int ans=0;

        for(r=0;r<n;r++){
            // for(auto [i,j]:st)  {cout<<i<<" "<<j<<endl;}
            // cout<<endl;
            while(st.size()==2 and (st.find(fruits[r])==st.end())){
                st[fruits[l]]--;
                // cout<<st[fruits[l]]<<" x "<<endl;
                if(st[fruits[l]]==0)    st.erase(fruits[l]);
                l++;
            }
            st[fruits[r]]++;
            int present=r-l+1;
            ans=max(ans,present);
        }
        return ans;
    }
};
