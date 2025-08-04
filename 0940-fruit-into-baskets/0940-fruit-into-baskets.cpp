class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        const int MAX_TYPE = 100000;
        vector<int> count(MAX_TYPE + 1, 0);
        int l = 0, distinct = 0, maxLen = 0;

        for (int r = 0; r < fruits.size(); r++) {
            if (count[fruits[r]]++ == 0)
                distinct++; 

            while (distinct > 2) {
                if (--count[fruits[l]] == 0)
                    distinct--;  
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
