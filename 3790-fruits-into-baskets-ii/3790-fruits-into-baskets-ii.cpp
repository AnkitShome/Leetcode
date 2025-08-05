class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();    
        int m=n;
        vector<int> vis(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i] and !vis[j]){
                    vis[j]=1;
                    m--;
                    break;
                }
            }
        }
        return m;
    }
};