class Solution {
public:
    bool isValidBST(TreeNode *root) {
        flag = true;
        search(root);
        return flag;
    }
private:
    bool flag;
    pair<int, int> search(TreeNode *root) {
        if (!root) return make_pair(0, 0);
        if (root->left == root->right) {
            return make_pair(root->val, root->val);
        }
        int a = root->val, b = root->val;
        if (root->left) {
            auto l = search(root->left);
            if (root->val <= l.second) {
                flag = false;
                return make_pair(0, 0);
            }
            a = l.first;
        }
        if (root->right) {
            auto r = search(root->right);
            if (root->val >= r.first) {
                flag = false;
                return make_pair(0, 0);
            }
            b = r.second;
        }
        return make_pair(a, b);
    }
};
