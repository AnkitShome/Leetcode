class Solution {
public:
    bool check(int mid,int m,int k,vector<int>& bloom){
        int n=bloom.size();
        int j=0,i=0;
        int days=0;
        while(j<n){
            // cout<<bloom[j]<<" "<<mid<<endl; // (optional) debug
            if(bloom[j]<=mid) { j++; continue; }
            else{
                days += (j - i) / k;
                i = j + 1;
            }
            j++;
        }
        days += (j - i) / k;
        // cout<<mid<<" "<<days<<endl<<endl;   // (optional) debug
        return days >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = (int)bloomDay.size();
        if ( (long long)m * k > n ) return -1;   // overflow-safe check

        // real search range: [min(bloomDay), max(bloomDay)]
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, m, k, bloomDay)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
