#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            unsigned long long minIndex = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < sz; i++) {
                auto [node, idx] = q.front();
                q.pop();

                unsigned long long normalized = idx - minIndex;

                if (i == 0) first = normalized;
                if (i == sz - 1) last = normalized;

                if (node->left) {
                    q.push({node->left, normalized * 2});
                }
                if (node->right) {
                    q.push({node->right, normalized * 2 + 1});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return (int)ans;
    }
};
