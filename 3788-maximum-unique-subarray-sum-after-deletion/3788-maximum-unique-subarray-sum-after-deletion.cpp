class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        int maxi=-1000;
        int sum=0;
        for(auto i:nums){
            maxi=max(maxi,i);
            if(st.count(i)) continue;
            if(i>0){
                sum+=i;
                st.insert(i);
            }
        }
        if(st.empty())  sum+=maxi;
        return sum;
    }
};