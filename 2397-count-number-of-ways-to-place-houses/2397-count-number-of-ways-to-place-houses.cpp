class Solution {
public:
    int countHousePlacements(int n) {
        const int mod = 1e9 + 7;
        long long a = 1, b = 2;  
        for (int i = 2; i <= n; ++i) {
            long long c = (a + b) % mod;
            a = b;
            b = c;
        }
        return (b * b) % mod;
    }
};
