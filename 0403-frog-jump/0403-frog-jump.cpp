class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        // Quick fail check
        if (stones[1] != 1) return false;

        // Map stone position → index
        unordered_map<int, int> posIndex;
        for (int i = 0; i < n; i++) posIndex[stones[i]] = i;

        // dp[i][jump] = true if we can reach stone i with a jump of length 'jump'
        static bool dp[2005][2005];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = true; // start at stone 0, jump = 0

        for (int ind = 0; ind < n; ind++) {
            for (int jump = 0; jump <= n; jump++) {
                if (!dp[ind][jump]) continue;
                for (int nextJump = jump - 1; nextJump <= jump + 1; nextJump++) {
                    if (nextJump <= 0) continue; // no backward or zero jumps
                    int nextPos = stones[ind] + nextJump;
                    if (posIndex.count(nextPos)) {
                        int nextIndex = posIndex[nextPos];
                        dp[nextIndex][nextJump] = true;
                    }
                }
            }
        }

        // If we can reach the last stone with any jump size
        for (int jump = 0; jump <= n; jump++) {
            if (dp[n-1][jump]) return true;
        }
        return false;
    }
};
