class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n),right(n);
        left[0]=height[0];
        right[n-1]=height[n-1];
        int ans=0;
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        } 
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            int bound=min(left[i],right[i]);
            ans+= ((bound-height[i])>0?bound-height[i]:0);
        }
        return ans;
    }
};