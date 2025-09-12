class Solution {
public:
  
    
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int ans = 0;

    for (int x : s) {               // iterate unique elements
        if (!s.count(x - 1)) {      // only start at beginning of a sequence
            int cur = 1;
            int next = x + 1;
            while (s.count(next)) {
                cur++;
                next++;
            }
            ans = max(ans, cur);
        }
    }
    return ans;
}

};