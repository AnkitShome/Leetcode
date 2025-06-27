class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> NGE(n, n), PGE(n, -1), NSE(n, n), PSE(n, -1);
        stack<int> st;
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if (!st.empty()) NGE[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if (!st.empty()) PGE[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if (!st.empty()) NSE[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if (!st.empty()) PSE[i] = st.top();
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            long long maxCount = (long long)(i - PGE[i]) * (NGE[i] - i);
            long long minCount = (long long)(i - PSE[i]) * (NSE[i] - i);
            total += (long long)nums[i] * (maxCount - minCount);
        }
        return total;
    }
};
