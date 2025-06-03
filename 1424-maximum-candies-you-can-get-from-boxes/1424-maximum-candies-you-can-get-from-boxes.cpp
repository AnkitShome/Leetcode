class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<int> vis(n, 0), eaten(n, 0);
        queue<int> q;

        for (int i : initialBoxes) {
            q.push(i);
            vis[i] = 1;
        }

        int candy = 0;

        while (!q.empty()) {
            int box = q.front(); q.pop();

            if (status[box] == 0 || eaten[box]) continue;

            candy += candies[box];
            eaten[box] = 1;

            for (int k : keys[box]) {
                status[k] = 1;
                if (vis[k] && !eaten[k])
                    q.push(k);
            }

            for (int b : containedBoxes[box]) {
                if (!eaten[b]) {
                    vis[b] = 1;
                    q.push(b);
                }
            }
        }

        return candy;
    }
};
