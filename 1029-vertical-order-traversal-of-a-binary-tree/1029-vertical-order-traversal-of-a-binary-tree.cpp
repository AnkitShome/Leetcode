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
    map<int,multiset<pair<int,int>>> mp;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<tuple<TreeNode*,int,int>> q;
        q.push({root,0,0});

        while(!q.empty()){
            auto [node,level,col]=q.front();
            q.pop();

            mp[col].insert({level,node->val});

            if(node->left)  q.push({node->left,level+1,col-1});
            if(node->right) q.push({node->right,level+1,col+1});
        }

        vector<vector<int>> ans;

        for(auto [x,y]:mp){
            vector<int> res;
            for(auto [i,j]:y){
                res.push_back(j);
            }
            ans.push_back(res);
        }
        return ans;
    }
};