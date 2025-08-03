class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> arr(1005);

        for(auto t:trips){
            int m=t[0],l=t[1],r=t[2];
            arr[l]+=m;
            arr[r]-=m;
        }

        int count=0;
        for(int i=0;i<=1000;i++){
            count+=arr[i];
            if(count>capacity)  return false;
        }
        return true;
    }
};