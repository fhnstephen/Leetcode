class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        f(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    template<typename T>
    TreeNode *f(T pb, T pe, T ib, T ie) {
        if (pb >= pe || ib >= ie) return nullptr;
        auto cur = *pb;
        auto root = new TreeNode(cur);
        auto i = ie - 1;
        auto size = 0;
        while (i != ib && *i != cur) --i, ++size;
        root->left = f(pb + 1, pe - size, ib, i);
        root->right = f(pe - size, pe, i + 1, ie);
        return root;
    }
};
