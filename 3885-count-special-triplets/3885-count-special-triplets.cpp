class Solution {
public:
    int mod = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        long long ans = 0;
        for (auto& it : mp) {
            int num = it.first;
            int count = it.second.size();
            int val = num * 2;

            if (num == 0) {
                if (count >= 3) {
                    long long comb = (1LL * count * (count - 1) % mod * (count - 2)) % mod;
                    comb = (comb * 166666668LL) % mod; 
                    ans = (ans + comb) % mod;
                }
                continue;
            }

            if (!mp.count(val)) continue;

            const vector<int>& vec2 = mp[val];
            int m = vec2.size();

            for (int i : it.second) {
                int idx = upper_bound(vec2.begin(), vec2.end(), i) - vec2.begin();
                int left = idx;
                int right = m - idx;
                ans = (ans + 1LL * left * right % mod) % mod;
            }
        }

        return ans;
    }
};
