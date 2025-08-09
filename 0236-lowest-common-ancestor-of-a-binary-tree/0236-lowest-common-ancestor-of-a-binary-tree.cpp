/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* ans=NULL;

    bool dfs(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root)   return false;

        bool left=dfs(root->left,p,q);
        bool right=dfs(root->right,p,q);

        bool forward=false;
        if(left and right and !ans) ans=root;
        if(left and (root==p or root==q) and !ans)  ans=root;
        if(right and (root==p or root==q) and !ans)  ans=root;

        if(root==p or root==q)  forward=true;

        return (forward or left or right);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool b=dfs(root,p,q);
        return ans;
    }
};