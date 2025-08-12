/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        queue<TreeNode*> q;
        q.push(root);

        int level=0;
    
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node)    {
                s+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
            else    s+="null,";
        }
        if(!s.empty())  s.pop_back();
        return s;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="null")    return nullptr;

        vector<string> nodes;
        string token="";

        for(int i=0;i<=data.size();i++){
            if(i==data.size() or data[i]==','){
                nodes.push_back(token);
                token="";
            }
            else{
                token+=data[i];
            }
        }

        queue<TreeNode*> q;

        TreeNode* root=new TreeNode(stoi(nodes[0]));
        q.push(root);
        int idx=1;

        while(!q.empty() and idx<nodes.size()){
            TreeNode* root=q.front();
            q.pop();

            if(idx<nodes.size() and nodes[idx]!="null"){
                root->left=new TreeNode(stoi(nodes[idx]));
                q.push(root->left);
            }
            idx++;

            if(idx<nodes.size() and nodes[idx]!="null"){
                root->right=new TreeNode(stoi(nodes[idx]));
                q.push(root->right);
            }
            idx++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));