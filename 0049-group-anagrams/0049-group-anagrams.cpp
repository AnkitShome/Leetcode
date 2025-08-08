class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const string& s : strs) {
            string key = freqSignature(s);
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& [key, group] : mp) {
            res.push_back(move(group));
        }
        return res;
    }

private:
    string freqSignature(const string& s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        // Build key with delimiters to avoid ambiguity
        string key;
        for (int count : freq) {
            key += "#" + to_string(count);
        }
        return key;
    }
};
