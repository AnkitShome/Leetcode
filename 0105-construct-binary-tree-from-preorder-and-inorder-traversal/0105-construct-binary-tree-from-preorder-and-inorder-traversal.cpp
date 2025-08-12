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
    TreeNode* dfs(int pl,int pr,int il,int ir,vector<int>& pre,vector<int>& in){
        if(pl>pr or il>ir)  return NULL;
        TreeNode* root=new TreeNode(pre[pl]);

        int idx=-1;
        for(int i=il;i<=ir;i++){
            if(in[i]==root->val)    idx=i;
        }

        int left=idx-il;
        int right=ir-idx;

        root->left=dfs(pl+1,pl+left,il,idx-1,pre,in);
        root->right=dfs(pr-right+1,pr,idx+1,ir,pre,in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return dfs(0,n-1,0,n-1,preorder,inorder);
    }
};