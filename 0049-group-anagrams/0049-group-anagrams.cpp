class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(i);
        }
        vector<vector<string>> res;

        for(auto [i,a]:mp){
            vector<string> x;
            for(auto s:a){
                x.push_back(strs[s]);
            }
            res.push_back(x);
        }
        return res;
    }
};