class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<int> vis(n);
        queue<int> q;
        vector<int> key(n);
        for(auto i:initialBoxes)    {q.push(i);vis[i]++;}

        int candy=0;

        vector<int> eaten(n);

        while(!q.empty()){
            int box=q.front();
            q.pop();
            if(status[box]==0 and key[box]==0)  continue;
            
            if(vis[box]==1 and status[box]==1 and eaten[box]==0){
                candy+=candies[box];eaten[box]=1;
            }
                
            else if(vis[box]==1 and key[box]==1 and eaten[box]==0){
                candy+=candies[box];
                eaten[box]=1;
            }

            else    continue;

            for(auto it:keys[box]){
                key[it]=1;
                if(eaten[it])  continue;
                q.push(it);
            }
            for(auto it:containedBoxes[box]){
                if(eaten[it]) continue;
                vis[it]=1;
                q.push(it);
            }


        }
        return candy;
    }
};