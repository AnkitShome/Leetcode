class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            s=countSort(s);
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
    private:
    string countSort(string s){
        vector<int> freq(26);
        for(auto i:s){
            freq[i-'a']++;
        }
        string x="";
        for(auto i:freq){
            x+=i+'0';
        }
        return x;
    }
};