class Solution {
public:

    int N;
    int dp[10001][2][2];
    const int mod=1e9+7;

    int f(int i, int l, int r) {
        if (i == N) return 1;
        if (dp[i][l][r] != -1) return dp[i][l][r];

        long long res = 0;

        if (l && r) {
            res = f(i + 1, 0, 0);
        } 
        else if (!l && r) {
            res = f(i + 1, 1, 0);
            res = (res + f(i + 1, 0, 0)) % mod;
        } 
        else if (l && !r) {
            res = f(i + 1, 0, 0);
            res = (res + f(i + 1, 0, 1)) % mod;
        } 
        else {
            res = f(i + 1, 0, 0);
            res = (res + f(i + 1, 0, 1)) % mod;
            res = (res + f(i + 1, 1, 0)) % mod;
            res = (res + f(i + 1, 1, 1)) % mod;
        }

        return dp[i][l][r] = (int)(res % mod);
    }

    int countHousePlacements(int n) {
        N=n;
        memset(dp,-1,sizeof(dp));
        return f(0,0,0);
    }
};