class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        vector<int> pos(n),pre(n+1);
        for(int i=0;i<n;i++){
            pos[i]=fruits[i][0];
            pre[i+1]=fruits[i][1]+pre[i];
        }

        int l=0,r=0;
        int ans=0;
        for(int r=0;r<n;r++){
            int left=pos[l];
            int right=pos[r];

            int steps=(right-left)+min(abs(left-startPos),abs(right-startPos));

            while(l<r and steps>k){
                l++;
                left=pos[l];
                steps=(right-left)+min(abs(left-startPos),abs(right-startPos));
            }
            
            if(l<=r and steps<=k){
                int cost=pre[r+1]-pre[l];
                ans=max(ans,cost);
            }
        }
        return ans;
    }
};