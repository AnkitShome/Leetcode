class Solution {
public:
    int dp[10][2][10][2]; 

    int f(int pos, int tight, int countOne, int started, const vector<int>& digits) {
        if (pos == digits.size()) {
            return countOne;
        }

        if (dp[pos][tight][countOne][started] != -1) return dp[pos][tight][countOne][started];

        int limit = tight ? digits[pos] : 9;
        int res = 0;

        for (int d = 0; d <= limit; d++) {
            int newTight = tight && (d == limit);
            int newStarted = started || (d > 0);
            int newCountOne = countOne + ((newStarted && d == 1) ? 1 : 0);
            res += f(pos + 1, newTight, newCountOne, newStarted, digits);
        }

        return dp[pos][tight][countOne][started] = res;
    }

    int countDigitOne(int n) {
        if (n < 1) return 0;

        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());

        memset(dp, -1, sizeof(dp));
        return f(0, 1, 0, 0, digits);
    }
};
