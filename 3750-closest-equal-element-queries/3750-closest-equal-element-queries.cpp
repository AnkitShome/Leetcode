class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(auto q:queries){
            int num=nums[q];
            if(mp[num].size()==1)   {ans.push_back(-1);continue;} 
            auto it=lower_bound(mp[num].begin(),mp[num].end(),q);
            int m=it-mp[num].begin();
            int sz=mp[num].size();

            int l=mp[num][(m-1+sz)%sz];
            int r=mp[num][(m+1+sz)%sz];
            int pos=mp[num][m];
            
            int left=(pos-l+n)%n;
            int right=(r-pos+n)%n;
            ans.push_back(min(left,right));
        }
        return ans;
    }
};