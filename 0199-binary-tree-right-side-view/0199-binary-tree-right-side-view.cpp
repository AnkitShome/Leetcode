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
    void dfs(TreeNode* root,int x,unordered_map<int,int>& res){
        if(!root)   return;
        res[x]=root->val;
        dfs(root->left,x+1,res);
        dfs(root->right,x+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int,int> res;
        dfs(root,0,res);
        vector<int> ans(res.size());
        for(auto [i,j]:res) ans[i]=j;
        return ans;
    }
};