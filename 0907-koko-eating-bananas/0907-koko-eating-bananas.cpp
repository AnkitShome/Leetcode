#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(long long mid, const vector<int>& piles, long long h) {
        long long total = 0;
        for (int x : piles) {
            total += (x + mid - 1) / mid; 
            if (total > h) return false;  
        }
        return total <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        long long low = 1, high = maxPile;      
        int ans = maxPile;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, piles, h)) {
                ans = (int)mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
