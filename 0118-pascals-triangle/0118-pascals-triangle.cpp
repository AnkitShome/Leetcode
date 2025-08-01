class Solution {
public:

    //nums[i][j]=nums[i-1][j-1]+nums[i-1][j]

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            vector<int> es(i+1);
            es[0]=1;
            es[i]=1;
            for(int j=1;j<i;j++){
                es[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(es);
        }
        return res;
    }
};