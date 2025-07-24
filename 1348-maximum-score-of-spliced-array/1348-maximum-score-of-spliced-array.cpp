class Solution {
public:
    int n;

    int kadane(vector<int>& nums1,vector<int>& nums2){
        int cur=0,ans=0;
        for(int i=0;i<n;i++){
            int diff=nums2[i]-nums1[i];
            cur=max(cur+diff,diff);
            ans=max(ans,cur);
        }
        return ans;
    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        int s=0,t=0;
        for(int i=0;i<n;i++){
            s+=nums1[i];t+=nums2[i];
        }
        s+=kadane(nums1,nums2);
        t+=kadane(nums2,nums1);
        return max(s,t);
    }
};