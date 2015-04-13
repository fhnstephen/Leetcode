class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return f(num.begin(), num.end());
    }
private:
    template<typename T>
    TreeNode *f(T l, T r) {
        if (l == r - 1) {
            return new TreeNode(*l);
        }
        if (l >= r) return nullptr;
        auto mid = l + (r - l) / 2;
        auto root = new TreeNode(*mid);
        root->left = f(l, mid);
        root->right = f(mid + 1, r);
        return root;
    }
};
