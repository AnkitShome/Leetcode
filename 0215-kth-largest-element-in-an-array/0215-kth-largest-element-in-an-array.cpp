class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i:nums){
            pq.push(i);
        }
        int cnt=1;
        while(cnt<k){
            pq.pop();
            cnt++;
        }
        return pq.top();
    }
};