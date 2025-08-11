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
    set<int> res;

    int dfs1(TreeNode* root,TreeNode* target,int k){
        if(!root)   return INT_MIN;
        if(root==target)    return 0;

        int left=dfs1(root->left,target,k)+1;
        
        if(left>0 and left<=k){
            if(left==k) res.insert(root->val);
            else dfs2(root->right,k-left-1);
            return left;
        }
        
        int right=dfs1(root->right,target,k)+1;
        
        if(right>0 and right<=k){
            if(right==k)    res.insert(root->val);
            else dfs2(root->left,k-right-1);
            return right;
        }
        return INT_MIN;
    }

    void dfs2(TreeNode* root,int step){
        if(!root)   return;
        if(step==0){
            res.insert(root->val);
            return;
        }
        dfs2(root->left,step-1);
        dfs2(root->right,step-1);
    }

    void dfs3(TreeNode* root,int step,int k){
        if(!root)   return;
        if(step==k){
            res.insert(root->val);
            return;
        }
        dfs3(root->left,step+1,k);
        dfs3(root->right,step+1,k);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs3(target,0,k);
        int x=dfs1(root,target,k);
        vector<int> ans;
        for(auto i:res) ans.push_back(i);
        return ans;
    }
};