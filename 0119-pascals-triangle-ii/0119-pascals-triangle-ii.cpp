class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for(int i=0;i<rowIndex+1;i++){
            vector<int> es(i+1);
            es[0]=1;
            es[i]=1;
            for(int j=1;j<i;j++){
                es[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(es);
        }
        return res[rowIndex];        
    }
};
