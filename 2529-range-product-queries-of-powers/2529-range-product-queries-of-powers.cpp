class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    long long modInverse(long long a, long long mod) {
        return modPow(a, mod - 2, mod);
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> arr;
        
        for (int i = 31; i >= 0; i--) {
            if (n & (1 << i)) {
                arr.push_back(1 << i);
            }
        }

        sort(arr.begin(), arr.end());
        int m = arr.size();
        
        vector<long long> pre(m + 1, 1);
        for (int i = 0; i < m; i++) {
            pre[i + 1] = (pre[i] * arr[i]) % MOD;
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long product = (pre[r + 1] * modInverse(pre[l], MOD)) % MOD;
            ans.push_back(product);
        }

        return ans;
    }
};
