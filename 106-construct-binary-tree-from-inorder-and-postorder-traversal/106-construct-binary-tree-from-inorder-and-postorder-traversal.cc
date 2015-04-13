class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return f(postorder.begin(), postorder.end(), inorder.begin(), inorder.end());
    }
private:
    template<typename T>
    TreeNode *f(T pb, T pe, T ib, T ie) {
        if (pb >= pe || ib >= ie) return nullptr;
        auto cur = *(pe - 1);
        auto root = new TreeNode(cur);
        auto i = ib;
        auto size = 0;
        while (i != ie && *i != cur) ++i, ++size;
        root->left = f(pb, pb + size, ib, i);
        root->right = f(pb + size, pe - 1, i + 1, ie);
        return root;
    }
};
