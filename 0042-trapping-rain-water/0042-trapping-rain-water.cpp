class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int left=height[0],right=height[n-1];
        int ans=0;
        while(i<=j){
            if(left<=right){
                left=max(left,height[i]);
                ans+=(left-height[i]);
                i++;
            }
            else{
                right=max(right,height[j]);
                ans+=(right-height[j]);
                j--;
            }
        }
        return ans;
    }
};