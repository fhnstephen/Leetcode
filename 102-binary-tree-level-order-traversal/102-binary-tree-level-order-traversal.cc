/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr); // as divided node
        vector<vector<int>> temp;
        vector<int> cur;
        if (!root) return temp;
        while (!q.empty()) {
            TreeNode *x = q.front();
            q.pop();
            if (x == nullptr) {
                temp.push_back(cur);
                cur.clear();
                if (q.empty())
                    break;
                q.push(nullptr);
            }
            else {
                cur.push_back(x->val);
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
            }
        }
        return temp;
    }
};
