/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int grid[1005][2005];

    map<int,multiset<pair<int,int>>> mp;

    void dfs(TreeNode* root,int x,int y){
        if(!root)   return;
        mp[y].insert({x,root->val});
        dfs(root->left,x+1,y-1);
        dfs(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        memset(grid,-1,sizeof(grid));
        dfs(root,0,0);
        vector<vector<int>> ans;
        for(auto [i,v]:mp){
            vector<int> cur;
            for(auto [x,j]:v){
                cur.push_back(j);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};