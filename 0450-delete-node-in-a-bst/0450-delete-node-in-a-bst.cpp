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
    TreeNode* dfs(TreeNode* root,int key){
        if(!root)   return nullptr;

        if(root->val>key)
            root->left=dfs(root->left,key);

        if(root->val<key)
            root->right=dfs(root->right,key);

        if(root->val==key){
            if(!root->left){
                return root->right;
            }
            if(!root->right){
                return root->left;
            }

            TreeNode* righty=root->right;
            TreeNode* prev=root->left;
            TreeNode* cur=root->left;

            while(cur->right){
                cur=cur->right;
            }

            cur->right=righty;
            return prev;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return dfs(root,key);
    }
};