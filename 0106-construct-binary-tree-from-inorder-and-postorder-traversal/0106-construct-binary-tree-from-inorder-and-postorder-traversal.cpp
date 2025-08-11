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
    int n;
    TreeNode* dfs(int i,int j,int l,int r,vector<int>& in,vector<int>& post){

        if (i > j || l > r) return nullptr;

        TreeNode* root=new TreeNode(post[r]);
        root->left=NULL;
        root->right=NULL;

        int x=-1;
        for(int k=0;k<n;k++){
            if(in[k]==post[r]){
                x=k;break;
            }
        }

        int left=x-i;
        int right=j-x;
        
        root->right=dfs(x+1,j,r-right,r-1,in,post);
        root->left=dfs(i,x-1,l,l+left-1,in,post);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n=inorder.size();
        return dfs(0,n-1,0,n-1,inorder,postorder);      
    }
};